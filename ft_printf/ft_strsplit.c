/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:50:16 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/04 16:15:11 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_words_len(const char *s, char c)
{
	size_t			i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static size_t		ft_count_w(const char *s, char c)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && s[i] != '\0')
			i++;
		if (s[i])
			count++;
		while (!(s[i] == c) && s[i] != '\0')
			i++;
	}
	return (count);
}

static char			*ft_paswd(const char *s, size_t len)
{
	char			*word;
	size_t			i;

	i = 0;
	if ((word = (char *)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**str;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (ft_count_w(s, c) + 1))))
		return (NULL);
	while (i < ft_count_w(s, c))
	{
		while ((s[j] == c))
			j++;
		if ((str[i] = ft_paswd(s + j, ft_words_len(s + j, c))) == NULL)
			return (NULL);
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	str[i] = 0;
	return (str);
}
