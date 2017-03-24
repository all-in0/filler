/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:55:57 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 19:10:44 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*up_or(int up)
{
	char		*hex;

	if (up == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	return (hex);
}

char	*ft_itoa_base(long long value, int base, int up)
{
	int			i;
	long long	n;
	char		*s;
	char		*hex;

	hex = up_or(up);
	i = (value < 0 && base == 10) ? 2 : 1;
	n = value;
	while (n /= base)
		i++;
	if ((s = (char*)malloc(sizeof(char) * i + 1)) == 0)
		return (NULL);
	s[i] = 0;
	if (value < 0 && base == 10)
		s[0] = '-';
	if (value == 0)
		s[0] = '0';
	n = value;
	while (n)
	{
		s[--i] = hex[(n < 0) ? -(n % base) : n % base];
		n /= base;
	}
	return (s);
}
