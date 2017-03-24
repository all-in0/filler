/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:16:49 by vnakonec          #+#    #+#             */
/*   Updated: 2016/11/30 18:11:30 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "./ft_printf.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		b;
	char	*str;
	char	*str2;

	i = 0;
	str = (char *)s1;
	str2 = (char *)s2;
	while (str[i] != '\0')
	{
		b = 0;
		while (str2[b] == str[i + b])
		{
			if (str2[b + 1] == '\0')
				return (str + i);
			b++;
		}
		i++;
	}
	if (ft_strlen(str2) == 0)
		return (str);
	return (NULL);
}
