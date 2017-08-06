/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:33:17 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/23 12:33:19 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "filler.h"

int			try_paste(t_fil *ph, int i)
{
	int		b;
	int		a;

	b = -1;
	a = 0;
	while (ph->fig[++b] != '\0')
	{
		if (ph->fig[b] == '*' && (ph->map[i] == ph->sym ||
				ph->map[i] == ph->sym2))
			a++;
		if (ph->fig[b] == '*' && ((ph->map[i] == ph->sym3 ||
				ph->map[i] == ph->sym4) || ph->map[i] == '\n' ||
				ph->map[i] == '\0'))
			return (0);
		if (ph->fig[b] == '.' && (ph->map[i] == '\n' || ph->map[i] == '\0'))
			return (0);
		if (ph->fig[b] == '\n')
			i = i + ph->x - ph->fig_x + 1;
		else
			i++;
	}
	return (a == 1 ? 1 : 0);
}

bool		find_place(t_fil *phars)
{
	int i;

	i = -1;
	make_koef(phars);
	while (++i <= ((phars->x + 1) * (phars->y) - (phars->x * phars->fig_y) +
		(phars->x - phars->fig_x) - phars->fig_y))
		if (try_paste(phars, i))
			check_koef(phars, i);
	if (phars->co == 0)
		return (0);
	return (1);
}

bool		print_fig(t_fil *phar)
{
	int a;
	int b;

	a = phar->find_plase / (phar->x + 1);
	b = phar->find_plase % (phar->x + 1);
	ft_printf("%d %d\n", a, b);
	return (true);
}

int			main(void)
{
	t_fil		phars;
	int			pr;

	pr = 1;
	__builtin_bzero(&phars, sizeof(phars));
	save_all(&phars, 0);
	while (pr == 1)
	{
		phars.y = 0;
		phars.x = 0;
		phars.find_plase = 0;
		phars.co = 0;
		save_map(&phars, 0);
		save_fig(&phars, 0);
		pr = find_place(&phars);
		print_fig(&phars);
		__builtin_bzero(phars.imap, sizeof(phars.imap));
	}
	return (0);
}
