/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:11:23 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/06 16:39:55 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		b;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	b = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (i == b + 1)
	{
		str = ft_strsub(s, 0, 0);
		return (str);
	}
	while (s[b] == ' ' || s[b] == '\t' || s[b] == '\n')
		b--;
	str = ft_strsub(s, i, b - i + 1);
	return (str);
}
