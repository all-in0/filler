/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:56:46 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 16:19:38 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*str;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	b = 0;
	while (s2[b])
	{
		str[i] = s2[b];
		i++;
		b++;
	}
	str[i] = 0;
	return (str);
}
