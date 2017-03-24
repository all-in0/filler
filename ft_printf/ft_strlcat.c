/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:45:59 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/01 16:54:12 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./ft_printf.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		b;
	size_t		d;
	size_t		s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	b = 0;
	while (dst[i] != '\0')
		i++;
	if (i > size)
		return (s + size);
	while (src[b] != '\0' && (i < size - 1))
	{
		dst[i] = src[b];
		i++;
		b++;
	}
	dst[i] = '\0';
	return (s + d);
}
