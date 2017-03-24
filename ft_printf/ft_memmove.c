/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:24:09 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/01 17:07:49 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t count)
{
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	if (s != dst)
	{
		if (s < d)
			while (count--)
				d[count] = s[count];
		if (s > d)
			while (count--)
				*d++ = *s++;
	}
	return (dst);
}
