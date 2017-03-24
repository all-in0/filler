/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:12:00 by vnakonec          #+#    #+#             */
/*   Updated: 2016/11/30 18:01:34 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "./ft_printf.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int		i;
	char				*s1;

	i = 0;
	if (!s)
		return (0);
	s1 = (char *)malloc(ft_strlen((char *)s) + 1);
	if (!s1)
		return (0);
	while (s[i] != '\0')
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
