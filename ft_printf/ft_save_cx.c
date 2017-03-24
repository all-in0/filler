/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_cx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:10:48 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 16:11:00 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		save_x2(t_prf *phar, va_list ap)
{
	if (phar->spec == 'X' && phar->length == 0)
		phar->str = ft_itoa_base(va_arg(ap, unsigned int), 16, 1);
	if (phar->spec == 'X' && phar->length == 1)
		phar->str = ft_itoa_base((unsigned char)
			(va_arg(ap, unsigned int)), 16, 1);
	if (phar->spec == 'X' && phar->length == 2)
		phar->str = ft_itoa_base((unsigned short int)
			(va_arg(ap, unsigned int)), 16, 1);
	if (phar->spec == 'X' && phar->length == 3)
		phar->str = ft_a_itoa_base_unsig((va_arg(ap, unsigned long long)), 16);
	if (phar->spec == 'X' && phar->length == 4)
		phar->str = ft_a_itoa_base_unsig((va_arg(ap, unsigned long int)), 16);
	if (phar->spec == 'X' && phar->length == 5)
		phar->str = ft_a_itoa_base_unsig((va_arg(ap, uintmax_t)), 16);
	if (phar->spec == 'X' && phar->length == 6)
		phar->str = ft_a_itoa_base_unsig((va_arg(ap, size_t)), 16);
	if (phar->spec == 'X' && phar->length == 7)
		phar->str = ft_itoa_base((va_arg(ap, long)), 16, 1);
	return (1);
}

int		save_x(t_prf *phar, va_list ap)
{
	if (phar->spec == 'x' && phar->length == 0)
		phar->str = ft_itoa_base(va_arg(ap, unsigned int), 16, 0);
	if (phar->spec == 'x' && phar->length == 1)
		phar->str = ft_itoa_base((unsigned char)
			(va_arg(ap, unsigned int)), 16, 0);
	if (phar->spec == 'x' && phar->length == 2)
		phar->str = ft_itoa_base((unsigned short int)(va_arg(ap, int)), 16, 0);
	if (phar->spec == 'x' && phar->length == 3)
		phar->str = ft_itoa_base_unsig((va_arg(ap, unsigned long long)), 16);
	if (phar->spec == 'x' && phar->length == 4)
		phar->str = ft_itoa_base_unsig((va_arg(ap, unsigned long int)), 16);
	if (phar->spec == 'x' && phar->length == 5)
		phar->str = ft_itoa_base_unsig((va_arg(ap, uintmax_t)), 16);
	if (phar->spec == 'x' && phar->length == 6)
		phar->str = ft_itoa_base_unsig((va_arg(ap, size_t)), 16);
	if (phar->spec == 'x' && phar->length == 7)
		phar->str = ft_itoa_base((va_arg(ap, long)), 16, 0);
	if (phar->spec == 'X')
		save_x2(phar, ap);
	return (1);
}

int		save_c(t_prf *phar, va_list ap)
{
	phar->str = ft_strnew(2);
	if (phar->spec == 'c' || phar->spec == 'C')
	{
		phar->str[0] = va_arg(ap, int);
		phar->str[1] = '\0';
	}
	else
	{
		phar->str[0] = phar->spec;
		phar->str[1] = '\0';
		phar->spec = 'c';
	}
	return (1);
}
