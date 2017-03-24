/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:52:21 by vnakonec          #+#    #+#             */
/*   Updated: 2016/11/29 17:23:08 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		if (((char *)src)[i] == c)
		{
			((char *)dst)[i] = ((char *)src)[i];
			return ((char *)dst + ++i);
		}
		((char *)dst)[i] = ((char *)src)[i];
		i++;
		n--;
	}
	return (NULL);
}
