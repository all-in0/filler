/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:52:03 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 19:02:40 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_w2(t_prf *phar)
{
	char	*s;

	s = (char *)malloc(sizeof(s) * phar->width);
	s[phar->width] = '\0';
	s[0] = '\0';
	if (phar->width > phar->prec)
		phar->str = ft_strncat(s, phar->str, phar->width);
	else
		phar->str = ft_strncat(s, phar->str, phar->prec);
	return (0);
}

int		make_width(t_prf *phar)
{
	int		i;
	int		b;
	char	*s;
	char	d;

	b = 0;
	d = ' ';
	if (phar->flags[3] > 0 && phar->flags[0] == 0)
		d = '0';
	if ((i = phar->width - ft_strlen(phar->str)) > 0)
	{
		s = (char *)malloc(sizeof(s) * i + 1);
		while (b < i)
			s[b++] = d;
		s[b] = '\0';
		if (phar->flags[0] == 0)
			phar->str = ft_strjoin(s, phar->str);
		else
			phar->str = ft_strjoin(phar->str, s);
	}
	else if (b < phar->width && phar->spec == 's')
		make_w2(phar);
	return (0);
}
