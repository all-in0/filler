/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:12 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 19:07:14 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <stdlib.h>

static char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*rev;

	rev = (char *)malloc(ft_strlen(str) + 1);
	if (!rev)
		return (0);
	j = ft_strlen(str);
	i = 0;
	while (j > 0)
	{
		rev[i] = str[j - 1];
		i++;
		j--;
	}
	rev[i] = 0;
	return (rev);
}

char			*ft_uitoa(unsigned int n)
{
	int					i;
	char				*str;
	unsigned long long	ncpy;

	i = 0;
	ncpy = n;
	str = (char *)malloc(20);
	if (!str)
		return (0);
	while (ncpy >= 10)
	{
		str[i++] = ncpy % 10 + '0';
		ncpy /= 10;
	}
	str[i] = ncpy % 10 + '0';
	str[i + 1] = 0;
	return (ft_strrev(str));
}
