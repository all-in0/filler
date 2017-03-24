/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_it_base_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:57:10 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 18:58:08 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define RET(num) ((num < 0) ? (-num) : (num))

void	my_a(unsigned long long int value, int base, char *str, int *i)
{
	char	*b;

	b = "0123456789ABCDEF";
	if (value >= (unsigned long long)base)
		my_a(value / base, base, str, i);
	str[(*i)++] = b[RET(value % base)];
}

char	*ft_a_itoa_base_unsig(unsigned long long int value, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(str) * 40);
	ft_strclr(str);
	if (base < 2 || base > 16)
		return (NULL);
	my_a(value, base, str, &i);
	str[i] = '\0';
	if (ft_memchr("0123456789ABCDEF", str[i - 1], 16) == 0)
		str[i - 1] = '8';
	return (str);
}

void	my(unsigned long long int value, int base, char *str, int *i)
{
	char	*b;

	b = "0123456789abcdef";
	if (value >= (unsigned long long)base)
		my(value / base, base, str, i);
	str[(*i)++] = b[RET(value % base)];
}

char	*ft_itoa_base_unsig(unsigned long long int value, int base)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(str) * 40);
	ft_strclr(str);
	if (base < 2 || base > 16)
		return (NULL);
	my(value, base, str, &i);
	str[i] = '\0';
	if (ft_memchr("0123456789abcdef", str[i - 1], 16) == 0)
		str[i - 1] = '8';
	return (str);
}
