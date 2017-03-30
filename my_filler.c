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
#include "stdio.h"

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
			i = i + ph->fig_x + ph->x + 1;
		else
			i++;
	}
	if (a == 1)
		return (1);
	return (0);
}

int 	check_koef(t_fil *ph, int i)
{
	int a;
	int b;
	int c;

	a = i;
	b = -1;
	c = 0;
	while (ph->fig[++b] != '\0')
	{
		if (ph->fig[b] == '*') {
			a++;
			c = c + ph->imap[a];
		}
		else if (ph->fig[b] == '.')
			a++;
		else if (ph->fig[b] == '\n')
			a = a + ph->fig_x + ph->x + 1;
	}
	if (c < ph->co || ph->co == 0)
	{
		ph->co = c;
		ph->find_plase = i;
	}
	return (1);
}

int		make_koef(t_fil *ph)
{
	int		i;
	int		n;

	ph->imap = (int *)malloc(sizeof(ph->imap) * ph->x * ph->y + ph->y);
	n = 15;
	i = -1;
	while (ph->map[++i] > '\0')
		if (ph->map[i] == ph->sym4 || ph->map[i] == ph->sym3) {
			ph->imap[i] = n;
		}
	while (--n > 5)
	{
		i = -1;
		while (ph->map[++i] != '\0') {
			if (((ph->imap[i + 1] == (n + 1) || ph->imap[i - 1] == (n + 1) ||
				ph->imap[i + ph->x] == (n + 1) || ph->imap[i + ph->x + 1] == (n + 1) ||
				ph->imap[i + ph->x + 2] == (n + 1) || ph->imap[i - ph->x] == (n + 1) ||
				ph->imap[i - ph->x - 1] == (n + 1) || ph->imap[i - ph->x - 2] == (n + 1)) && ph->imap[i] < (n + 1)) && ph->imap[i] == 0)
				ph->imap[i] = n;
		}
	}
}

bool 	find_place(t_fil *phars) {
	int i;
	int a;
	int b;

	i = -1;
	a = 0;
	b = 0;
	make_koef(phars);
	while (++i <= (phars->x * (phars->y + 1)) - phars->fig_x * (phars->fig_y + 1))
		if (try_paste(phars, i))
			check_koef(phars, i);
	if (phars->co == 0)
		return (0);
	return (1);
}

bool	print_fig(t_fil *phar)
{
	int a;
	int b;

	a = phar->find_plase / (phar->x + 1);
	b = phar->find_plase % (phar->x + 1);
//	phars->map[i] = 'U';
//	ft_printf("%s", phars->map);
	ft_printf("%d %d\n", a, b);
	return (true);
}

int 	save_fig(t_fil *ph, int fd)
{
	int		a;
	int		i;
	int 	b;
	char	*line;

	b = -1;
	a = -1;
	get_next_line(fd, &line);
	ph->fig_y = ft_atoi(&line[5]);
	ph->fig_x = ft_atoi(&line[8]);
	ph->fig = (char *)malloc(sizeof(ph->fig) * ph->fig_y * ph->fig_x + ph->fig_y);
	while (++a < ph->fig_y && get_next_line(fd, &line))
	{
		i = -1;
		while (line[++i] != '\0')
			ph->fig[++b] = line[i];
		ph->fig[++b] = '\n';
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
	if (phars->y == 0 && phars->x == 0)
		return (0);
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
	t_fil phars;
	bool pr;
	int fd;
	int fd1;
	//FILE *f = fopen("file1.txt", "w");


	fd = open("/nfs/2016/v/vnakonec/filler/cmake-build-debug/file.txt", O_RDONLY);
	//fd = 0;
	pr = 1;
	__builtin_bzero(&phars, sizeof(phars));
	save_all(&phars, fd);
	while (pr == true)
	{
	if	(!save_map(&phars, fd) || !save_fig(&phars, fd))
	{
		ft_printf("0 0\n");
	}
	pr = find_place(&phars);
	print_fig(&phars);
	free(phars.map);
	free(phars.fig);
		phars.y = 0;
		phars.x = 0;
	}
	return (0);
}