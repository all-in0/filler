/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:53:22 by vnakonec          #+#    #+#             */
/*   Updated: 2016/11/30 18:04:18 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*a;
	size_t	i;

	i = 0;
	a = (char *)malloc(size);
	if (!a)
		return (0);
	while (i < size)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}
