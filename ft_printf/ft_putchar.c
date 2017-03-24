/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:29:56 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 15:46:37 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BIT_7 127
#define BIT_11 2047
#define BIT_16 65535
#define BIT_21 2097151
#define BIT_26 67108863
#define BIT31 2147483647

static void		ft_putchar2(const uint32_t s, char *rt)
{
	if (s <= BIT_21)
	{
		rt[0] = ((s & 1835008) >> 18) | 240;
		rt[1] = ((s & 258048) >> 12) | 128;
		rt[2] = ((s & 4032) >> 6) | 128;
		rt[3] = (s & 63) | 128;
	}
	else if (s <= BIT_26)
	{
		rt[0] = ((s & 50331648) >> 24) | 248;
		rt[1] = ((s & 16515072) >> 18) | 128;
		rt[2] = ((s & 258048) >> 12) | 128;
		rt[3] = ((s & 4032) >> 6) | 128;
		rt[4] = (s & 63) | 128;
	}
	else
	{
		rt[0] = ((s & 1073741824) >> 30) | 252;
		rt[1] = ((s & 1056964608) >> 24) | 128;
		rt[2] = ((s & 16515072) >> 18) | 128;
		rt[3] = ((s & 258048) >> 12) | 128;
		rt[4] = ((s & 4032) >> 6) | 128;
		rt[5] = (s & 63) | 128;
	}
}

size_t			ft_putchar(const uint32_t s)
{
	char		*rt;
	size_t		ct;

	rt = ft_strnew(6);
	if (s <= BIT_7)
		rt[0] = s;
	else if (s <= BIT_11)
	{
		rt[0] = ((s & 1984) >> 6) | 192;
		rt[1] = (s & 63) | 128;
	}
	else if (s <= BIT_16)
	{
		rt[0] = ((s & 61440) >> 12) | 224;
		rt[1] = ((s & 4032) >> 6) | 128;
		rt[2] = (s & 63) | 128;
	}
	else
		ft_putchar2(s, rt);
	ct = write(1, rt, sizeof(char)) + write(1, &rt[1], ft_strlen(&rt[1]));
	ft_strdel(&rt);
	return (ct);
}
