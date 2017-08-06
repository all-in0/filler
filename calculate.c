/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:21:36 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/03 18:28:15 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_koef(t_fil *ph, int i)
{
	int a;
	int b;
	int c;

	a = i;
	b = -1;
	c = 0;
	while (ph->fig[++b] != '\0')
	{
		if (ph->fig[b] == '*')
		{
			c = c + ph->imap[a];
			a++;
		}
		else if (ph->fig[b] == '.')
			a++;
		else if (ph->fig[b] == '\n')
			a = a - ph->fig_x + ph->x + 1;
	}
	if (c < ph->co || ph->co == 0)
	{
		ph->co = c;
		ph->find_plase = i;
	}
	return (1);
}

int			make_no(t_fil *ph, int i, int n)
{
	ph->imap = (int *)malloc(sizeof(ph->imap) * (ph->x + 1) * ph->y + 1);
	while (ph->map[++i] != '\0')
	{
		if (ph->map[i] == ph->sym4 || ph->map[i] == ph->sym3)
			ph->imap[i] = n;
		else if (ph->map[i] == '\n' || ph->map[i] == '\0')
			ph->imap[i] = -2;
	}
	ph->imap[i] = -2;
	return (1);
}

void		make_koef(t_fil *ph)
{
	int		i;
	int		n;

	n = make_no(ph, -1, 1);
	while (++n < 150)
	{
		i = -1;
		while (ph->map[++i] != '\0')
		{
			if (ph->map[i] == '\0')
				break ;
			if ((((i < (ph->x + 1) * ph->y - 1 && ph->imap[i + 1] == (n - 1))
				|| (i > 0 && ph->imap[i - 1] == (n - 1)) || (i < (ph->x + 1) *
				ph->y - 1 - ph->x && ph->imap[i + ph->x] == (n - 1)) ||
				(i < ((ph->x + 1) * ph->y) - ph->x - 2 &&
				ph->imap[i + ph->x + 1] == (n - 1)) ||
				(i < ((ph->x + 1) * ph->y) - ph->x - 3 &&
				ph->imap[i + ph->x + 2] == (n - 1)) ||
				(i > ph->x + 1 && ph->imap[i - ph->x] == (n - 1)) ||
				(i > ph->x + 2 && ph->imap[i - ph->x - 1] == (n - 1)) ||
				(i > ph->x + 3 && ph->imap[i - ph->x - 2] == (n - 1))) &&
				ph->imap[i] < (n - 1)) && ph->imap[i] == 0)
				ph->imap[i] = n;
		}
	}
}
