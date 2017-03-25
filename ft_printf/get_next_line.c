/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:01:06 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/20 15:25:55 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_one(int i, char **save, char **line, int a)
{
	char	*tmp;
	char	*s1;
	int		t;

	t = 0;
	tmp = *save;
	while (tmp[a] != '\n' && tmp[a] != '\0')
		a++;
	*line = ft_strsub(tmp, 0, a);
	if (tmp[a] == '\n')
	{
		tmp = ft_strdup(&tmp[a + 1]);
		free(*save);
		*save = tmp;
		return (1);
	}
	if (tmp[a] == '\0')
	{
		tmp[0] = '\0';
		s1 = *line;
		if (i == 0 && s1[0] == '\0')
			t = 1;
	}
	return (t > 0 ? 2 : 1);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	static char	*save = "\0";
	char		*tmp;
	char		buffer[BUFF_SIZE + 1];

	if (fd < 0 || !(line) || BUFF_SIZE < 1)
		return (-1);
	while (!(ft_strchr(save, '\n')) && (i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		tmp = save;
		tmp = ft_strjoin(tmp, buffer);
		if (save[1] != '\0')
			free(save);
		save = tmp;
	}
	if (i < 0)
		return (-1);
	if ((ft_one(i, &save, &(*line), 0)) == 2 && i == 0)
		return (0);
	return (1);
}
