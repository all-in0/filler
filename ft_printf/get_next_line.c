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

int		get_next_ln(char **line, t_gnl **lst)
{
	int			i;
	char		*tmp;
	char		buffer[BUFF_SIZE + 1];

	if ((*lst)->content < 0 || !(line) || BUFF_SIZE < 1)
		return (-1);
	while (!(ft_strchr((*lst)->save, '\n')) &&
			(i = read((*lst)->content, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		tmp = (*lst)->save;
		tmp = ft_strjoin(tmp, buffer);
		if ((*lst)->save[1] != '\0')
			free((*lst)->save);
		(*lst)->save = tmp;
	}
	if (i < 0)
		return (-1);
	if ((ft_one(i, &(*lst)->save, &(*line), 0)) == 2 && i == 0)
		return (0);
	return (1);
}

t_gnl	*search_fd(const int ft, t_gnl **lst)
{
	t_gnl	*new_lst;

	while ((*lst)->next != NULL)
	{
		if ((*lst)->content == ft)
			break ;
		else
			(*lst) = (*lst)->next;
	}
	if (!(*lst)->save)
	{
		(*lst)->save = ft_strnew(0);
		ft_strclr((*lst)->save);
		(*lst)->content = ft;
	}
	else if ((*lst)->content != ft)
	{
		new_lst = (t_gnl *)malloc(sizeof(new_lst));
		(*lst)->next = new_lst;
		(*lst) = (*lst)->next;
		(*lst)->next = NULL;
		ft_strclr(((*lst)->save = ft_strnew(0)));
		(*lst)->content = ft;
	}
	return (*lst);
}

int		get_next_line(const int fd, char **line)
{
	int				a;
	static t_gnl	*get_n_line = NULL;
	t_gnl			*get_nl;

	if (get_n_line == NULL)
	{
		get_n_line = (t_gnl *)malloc(sizeof(get_n_line));
		get_n_line->content = fd;
		get_n_line->save = ft_strnew(0);
		ft_strclr(get_n_line->save);
		get_n_line->next = (t_gnl *)malloc(sizeof(get_n_line));
		get_n_line->next = NULL;
	}
	if (!(line) || BUFF_SIZE < 1)
		return (-1);
	get_nl = get_n_line;
	get_nl = search_fd(fd, (&get_nl));
	a = get_next_ln(&(*line), &get_nl);
	if (a <= 0)
		free(get_nl);
	return (a);
}
