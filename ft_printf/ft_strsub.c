/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:00:53 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/01 16:48:11 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;

	i = 0;
	if (!s)
		return (NULL);
	s1 = (char *)malloc(len + 1);
	if (!s1)
		return (NULL);
	while (s[start] && i < len)
	{
		s1[i] = s[start];
		start++;
		i++;
	}
	s1[i] = 0;
	return (s1);
}
