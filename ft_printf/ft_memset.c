/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:48:19 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/01 17:08:58 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *str, int ch, size_t len)
{
	char	*q;

	q = str;
	while (len != 0)
	{
		*q = ch;
		q++;
		len--;
	}
	return (str);
}
