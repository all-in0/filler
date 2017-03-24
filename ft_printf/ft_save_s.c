/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:20:07 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 16:22:44 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_big_s_strlen(wchar_t *s)
{
	size_t		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

char	*wchar_to_char(wchar_t *str)
{
	char	*s1;
	int		i;
	int		a;

	i = -1;
	a = -1;
	if (!str)
		return (NULL);
	i = ft_big_s_strlen(str) + 1;
	if (!(s1 = (char *)malloc((size_t)i)))
		return (NULL);
	while (++a < i)
		s1[a] = (char)str[a];
	return (s1);
}

int		save_s(t_prf *phar, va_list ap)
{
	if (phar->spec == 's' && phar->length != 4)
	{
		phar->str = va_arg(ap, char *);
		if (!phar->str)
		{
			phar->str = "(null)";
		}
	}
	else if (phar->spec == 'S' || (phar->spec == 's' && phar->length == 4))
	{
		phar->str = wchar_to_char(va_arg(ap, wchar_t *));
	}
	return (1);
}
