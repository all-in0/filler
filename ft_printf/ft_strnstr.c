/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:54:34 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/06 16:18:50 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./ft_printf.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		j;

	if (s2[0] == '\0')
		return ((char *)s1);
	j = ft_strlen(s2);
	while (*s1 && len >= j)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, j) == 0)
			return ((char *)s1);
		s1++;
		len--;
	}
	return (NULL);
}
