/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:59:56 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/06 17:38:48 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int		i;

	i = 0;
	if (len == 0)
		return (0);
	len--;
	while (s1[i] == s2[i] && s1[i] && s2[i] && len > 0)
	{
		i++;
		len--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
