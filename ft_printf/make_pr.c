/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:25:29 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 19:02:24 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_pr_2(t_prf *phar, int i, int b)
{
	char	*s;

	if ((ft_strchr(phar->str, '-') || ft_strchr(phar->str, '+')) &&
			phar->spec == 'd')
		i++;
	if (phar->spec == 'p')
		i += 2;
	s = (char *)malloc(sizeof(s) * i + 1);
	while (b++ < i - 1)
		s[b] = '0';
	s[b] = '\0';
	phar->str = ft_strjoin(s, phar->str);
	if (phar->str[b] == '+' || phar->str[b] == '-')
	{
		phar->str[0] = phar->str[b];
		phar->str[b] = '0';
	}
	return (0);
}

int		make_pr_3(t_prf *phar, int i, int b)
{
	char	*s;

	b++;
	while (i < 0)
	{
		b++;
		i++;
	}
	s = (char *)malloc(sizeof(s) * b + 1);
	phar->str = ft_strncpy(s, phar->str, phar->prec);
	return (0);
}

int		make_prec(t_prf *phar)
{
	int		i;
	int		b;

	b = -1;
	if (phar->spec == 'p' && phar->str[1] == 'x' && phar->prec == 0)
		phar->str[2] = '\0';
	else if (phar->prec == 0 && phar->spec != 'c' && phar->spec != 'd' &&
			(phar->flags[2] == 0 || phar->spec == 'x'))
		phar->str[0] = '\0';
	else if (phar->spec == 'd' && phar->str[0] == '0' &&
			phar->str[1] == '\0' && phar->prec == 0)
		phar->str[0] = '\0';
	else if ((i = phar->prec - ft_strlen(phar->str)) > 0 &&
			phar->spec != 's' && phar->spec != 'S' && phar->spec != 'c' &&
			phar->spec != 'C')
		make_pr_2(phar, i, b);
	else if (i < 0 && (phar->spec == 's' || phar->spec == 'S'))
		make_pr_3(phar, i, b);
	return (0);
}