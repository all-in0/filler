/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:31:48 by vnakonec          #+#    #+#             */
/*   Updated: 2016/11/29 17:34:47 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		if (((char *)str)[i] == (char)c)
			return ((char *)str + i);
		i++;
		n--;
	}
	return (NULL);
}
