/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:10:10 by vnakonec          #+#    #+#             */
/*   Updated: 2017/04/03 16:10:16 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			save_fig(t_fil *ph, int fd)
{
	int		a;
	int		i;
	int		b;
	char	*line;

	b = -1;
	a = -1;
	get_next_line(fd, &line);
	ph->fig_y = ft_atoi(&line[5]);
	ph->fig_x = ft_atoi(&line[8]);
	free(line);
	ph->fig = (char *)malloc(sizeof(ph->fig) * ph->fig_y *
							ph->fig_x + ph->fig_y);
	while (++a < ph->fig_y && get_next_line(fd, &line))
	{
		i = -1;
		while (line[++i] != '\0')
			ph->fig[++b] = line[i];
		ph->fig[++b] = '\n';
		free(line);
	}
	ph->fig[b] = '\0';
	return (1);
}

int			saving_map(t_fil *phars, int fd)
{
	char	*line;

	get_next_line(fd, &line);
	phars->y = ft_atoi(&line[7]);
	phars->x = ft_atoi(&line[11]);
	free(line);
	if (phars->y < 1 || phars->x < 1)
		return (0);
	phars->map = (char *)malloc(sizeof(phars->map) *
								(phars->x * phars->y + phars->y));
	get_next_line(fd, &line);
	free(line);
	return (-1);
}

int			save_map(t_fil *phars, int fd)
{
	int		a;
	char	*line;
	int		i;
	int		b;

	a = -1;
	b = saving_map(phars, fd);
	while (++b < phars->y && get_next_line(fd, &line))
	{
		i = -1;
		while (line[++i] != '\0')
		{
			if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
				continue ;
			a++;
			phars->map[a] = line[i];
		}
		phars->map[++a] = '\n';
		free(line);
	}
	phars->map[a] = '\0';
	return (1);
}

int			save_all(t_fil *phars, int fd)
{
	char *line;

	get_next_line(fd, &line);
	phars->pl = line[10] - '0';
	free(line);
	if (phars->pl == 1)
	{
		phars->sym = 'O';
		phars->sym2 = 'o';
		phars->sym3 = 'x';
		phars->sym4 = 'X';
	}
	if (phars->pl == 2)
	{
		phars->sym = 'x';
		phars->sym2 = 'X';
		phars->sym3 = 'O';
		phars->sym4 = 'o';
	}
	return (0);
}
