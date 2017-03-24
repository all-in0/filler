/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:29:59 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 15:32:38 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		test_symb(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ')
		return (1);
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 't' || c == 'L')
		return (2);
	if (c == '.')
		return (3);
	if ((c <= '9' && c >= '1') || c == '*')
		return (4);
	if (c == '\0')
		return (5);
	return (0);
}

int		flags(const char *str, t_prf *phar)
{
	int i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == '#' ||
			str[i] == '0' || str[i] == ' ')
	{
		if (str[i] == '-')
			phar->flags[0] = 1;
		if (str[i] == '+')
			phar->flags[1] = 1;
		if (str[i] == '#')
			phar->flags[2] = 1;
		if (str[i] == '0')
			phar->flags[3] = 1;
		if (str[i] == ' ')
			phar->flags[4] = 1;
		i++;
	}
	return (i);
}

int		width(const char *str, t_prf *phar, va_list ap)
{
	int i;

	i = 0;
	phar->width = 0;
	if (str[0] == '*')
	{
		phar->width = va_arg(ap, int);
		if (phar->width < 0)
		{
			phar->flags[0] = 1;
			phar->width = -(phar->width);
		}
	}
	else
		phar->width = ft_atoi((char *)str);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[0] != '*')
		return (i);
	return (1);
}

int		prec(const char *str, t_prf *phar, va_list ap)
{
	int i;

	i = 0;
	phar->pr = 1;
	if (str[i] == '*')
		phar->prec = va_arg(ap, int);
	else
		phar->prec = ft_atoi((char *)str);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[0] != '*')
		return (i);
	return (1);
}

int		length(const char *str, t_prf *phar)
{
	int i;

	i = 0;
	if (str[i] == 'h' && str[i + 1] == 'h')
		phar->length = 1;
	if (str[i] == 'h' && str[i + 1] != 'h')
		phar->length = 2;
	if (str[i] == 'l' && str[i + 1] == 'l')
		phar->length = 3;
	if (str[i] == 'l' && str[i + 1] != 'l')
		phar->length = 4;
	if (str[i] == 'j')
		phar->length = 5;
	if (str[i] == 'z')
		phar->length = 6;
	if (str[i] == 't')
		phar->length = 7;
	if (str[i] == 'L')
		phar->length = 8;
	if (phar->length == 1 || phar->length == 3)
		return (2);
	return (1);
}
