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

bool	print_fig(t_fil *phar)
{

}

int 	save_fig(t_fil *ph)
{
	int		a;
	int		i;
	int 	b;
	char	*line;

	b = -1;
	a = -1;
	get_next_line(0, &line);
	ph->fig_y = ft_atoi(&line[5]);
	ph->fig_x = ft_atoi(&line[8]);
	ph->fig = (char *)malloc(sizeof(ph->fig) * ph->fig_y * ph->fig_x);
	while (++a < ph->fig_y && get_next_line(0, &line))
	{
		i = -1;
		while (line[++i] != '\0' && ph->fig[++b])
			ph->fig[b] = line[i];
		ph->fig[b++] = '\n';
	}
	ph->fig[b] = '\0';
}

int		copy_map(t_fil *phars, char *line)
{
	static int	a = -1;
	int			i;

	i = -1;
	if (a > 0 && phars->map[a] == '\0')
		phars->map[a] = '\n';
	while (line[++i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
			phars->map[a] = line[i];
		else
		{
			a++;
			phars->map[a] = line[i];
		}
	}
	phars->map[++a] = '\0';

}

int		save_all(t_fil *phars)
{
	char *line;
	int	a;

	a = -1;
	while (get_next_line(0, &line) && !ft_strstr(line, "a.out")) //plug
		free(line);
	phars->pl = line[10] - '0';
	while (get_next_line(0, &line) && !ft_strstr(line, "Plateau")) //plug
		free(line);
	phars->y = ft_atoi(&line[7]);
	phars->x = ft_atoi(&line[11]);
	phars->map = (char *)malloc(sizeof(phars->map) * (phars->x * phars->y));
	get_next_line(0, &line);
	while (++a <= phars->y)
		copy_map(phars, line);
}

int		main(int argc, char **argv)
{
	t_fil	phars;
	bool	pr;

	pr = 1;
	__builtin_bzero(&phars, sizeof(phars));
	//int fd = open("/nfs/2016/v/vnakonec/filler/example", O_RDONLY);
	save_all(&phars);
	while (pr == true)
	{
		save_fig(&phars);
		pr = print_fig(&phars);
		free(phars.fig);
	}
	return(0);
}