/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kostuli.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:33:04 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 15:51:28 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strload(char *str, int a)
{
	int		i;
	int		b;

	i = 0;
	while (str[i] != a)
		i++;
	b = i;
	while (str[b] == a)
		b++;
	while (i != 0)
	{
		i--;
		b--;
		str[b] = str[i];
	}
	while (b != 0)
	{
		b--;
		str[b] = (char)a;
	}
	return (str);
}

int		kostuli_2(t_prf *phar, int a, int i)
{
	if (phar->str[a + 1] != 'x' && phar->str[a + 1] != 'X')
	{
		if (phar->str[i] == '+' || phar->str[i] == '-')
			phar->str[a] = phar->str[i];
		if (phar->str[i] == 'x' || phar->str[i] == 'X')
			phar->str[a + 1] = phar->str[i];
		if (phar->str[i] == '+' || phar->str[i] == '-')
			phar->str[i] = '0';
		if (phar->str[i] == 'x' || phar->str[i] == 'X')
			phar->str[i] = '0';
	}
	return (0);
}

int		kostuli_3(t_prf *phar)
{
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->flags[0] != 1 &&
			phar->str[0] != ' ' && phar->str[ft_strlen(phar->str)] != ' ')
		if (ft_strchr(phar->str, ' '))
			phar->str = ft_strload(phar->str, ' ');
	return (0);
}

int		kostuli(t_prf *phar)
{
	int i;
	int a;

	a = 0;
	while (phar->str[a] == ' ')
		a++;
	i = a;
	while (phar->str[i] == '0')
		i++;
	if (phar->str[a] == '0')
		kostuli_2(phar, a, i);
	i = 0;
	if (phar->prec <= phar->width && (phar->spec == 'd' || phar->spec == 'i'))
	{
		a = ft_strlen(phar->str);
		while (phar->pr == 1 && a - i > phar->prec &&
				phar->prec >= 0 && phar->flags[0] == 0)
		{
			if (phar->str[i] == ' ' || phar->str[i] == '0')
				phar->str[i] = ' ';
			i++;
		}
	}
	kostuli_3(phar);
	return (0);
}
