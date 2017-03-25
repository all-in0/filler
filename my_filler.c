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

int 	try_paste(t_fil *ph, int i)
{
	int b;
	int a;

	b = -1;
	a = 0;
	while (ph->fig[++b] != '\0')
	{
		if ((ph->map[i] == ph->sym || ph->map[i] == ph->sym2) && ph->fig[b] == '*')
			a++;
		if (((ph->map[i] == ph->sym3 || ph->map[i] == ph->sym4) &&
			 ph->fig[b] == '*') || ph->map[i] == '\n')
			return (0);
		if (ph->fig[b] == '\n')
			i = i - ph->fig_x + ph->x + 1;
		else
			i++;
	}
	return (a == 1 ? 1 : 0);
}

int 	check_koef(t_fil *phars, int i)
{
	int a;
	int b;

	a = i / (phars->x + 1);
	b = i % (phars->x + 1);
//	phars->map[i] = 'U';
//	ft_printf("%s", phars->map);
	ft_printf("%d %d", a, b);
}

int 	find_place(t_fil *phars)
{
	int		i;
	int		a;
	int 	b;

	i = -1;
	a = 0;
	b = 0;
	while (phars->map[++i] != '\0')
		if(try_paste(phars, i) == 1) {
			check_koef(phars, i);
			break ;
		}
	return (0);
}

bool	print_fig(t_fil *phar)
{
	return (0);
}

int 	save_fig(t_fil *ph, int fd)
{
	int		a;
	int		i;
	int 	b;
	char	*line;

	b = -1;
	a = -1;
	if (ph->fig != NULL)
		free(ph->fig);
	get_next_line(fd, &line);
	ph->fig_y = ft_atoi(&line[5]);
	ph->fig_x = ft_atoi(&line[8]);
	free(line);
	ph->fig = (char *)malloc(sizeof(ph->fig) * ph->fig_y * ph->fig_x + 1);
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

int		save_map(t_fil *phars, int fd)
{
	int 	a;
	char 	*line;
	int		i;
	int		b;

	a = -1;
	b = -1;
	get_next_line(fd, &line);
	phars->y = ft_atoi(&line[7]);
	phars->x = ft_atoi(&line[11]);
	if (phars->map == NULL)
		phars->map = (char *)malloc(sizeof(phars->map) * (phars->x * phars->y + phars->y + 1));
	get_next_line(fd, &line);
	while (++b < phars->y && get_next_line(fd, &line))
	{
		i = -1;
		while (line[++i] != '\0')
		{
			if ((line[i] >= '0' && line[i] <= '9') || line[i] == ' ')
				continue ;
			else {
				a++;
				phars->map[a] = line[i];
			}
		}
		phars->map[++a] = '\n';
	}
	phars->map[a] = '\0';
}

int		save_all(t_fil *phars, int fd)
{
	char *line;

	while (!ft_strstr(line, "a.out")) {
		get_next_line(fd, &line);
		phars->pl = line[10] - '0';
	}
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

int		main(int argc, char **argv)
{
	t_fil	phars;
	bool	pr;
	int 	fd;
			//fd = open("/nfs/2016/v/vnakonec/filler/cmake-build-debug/file.txt", O_RDONLY);

	fd = 0;
	pr = 1;
	__builtin_bzero(&phars, sizeof(phars));
	save_all(&phars, fd);
	while (pr == true)
	{
		save_map(&phars, fd);
		save_fig(&phars, fd);
		find_place(&phars);
		pr = print_fig(&phars);
	}
	return(0);
}