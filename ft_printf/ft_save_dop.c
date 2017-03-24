/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_dop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:11:49 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 16:14:04 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		save_d(t_prf *phar, va_list ap)
{
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->length == 0)
		phar->str = ft_itoa(va_arg(ap, int));
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->length == 1)
		phar->str = ft_itoa((char)(va_arg(ap, int)));
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->length == 2)
		phar->str = ft_itoa((short int)(va_arg(ap, int)));
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->length == 3)
		phar->str = ft_itoa((va_arg(ap, long long)));
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->length == 4)
		phar->str = ft_itoa((va_arg(ap, long int)));
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->length == 5)
		phar->str = ft_itoa((intmax_t)(va_arg(ap, intmax_t)));
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->length == 6)
		phar->str = ft_itoa((va_arg(ap, size_t)));
	if ((phar->spec == 'd' || phar->spec == 'i') && phar->length == 7)
		phar->str = ft_itoa((va_arg(ap, long)));
	if (phar->spec == 'D')
		phar->str = ft_itoa(va_arg(ap, long long));
	return (0);
}

int		save_o(t_prf *phar, va_list ap)
{
	if (phar->spec == 'o' && phar->length == 0)
		phar->str = ft_itoa_base(va_arg(ap, unsigned int), 8, 0);
	if (phar->spec == 'o' && phar->length == 1)
		phar->str = ft_itoa_base((unsigned char)
			(va_arg(ap, unsigned int)), 8, 0);
	if (phar->spec == 'o' && phar->length == 2)
		phar->str = ft_itoa_base((unsigned short int)
			(va_arg(ap, unsigned int)), 8, 0);
	if (phar->spec == 'o' && phar->length == 3)
		phar->str = ft_itoa_base_unsig((va_arg(ap, unsigned long long)), 8);
	if (phar->spec == 'o' && phar->length == 4)
		phar->str = ft_itoa_base_unsig((va_arg(ap, unsigned long int)), 8);
	if (phar->spec == 'o' && phar->length == 5)
		phar->str = ft_itoa_base_unsig((va_arg(ap, uintmax_t)), 8);
	if (phar->spec == 'o' && phar->length == 6)
		phar->str = ft_itoa_base_unsig((va_arg(ap, size_t)), 8);
	if (phar->spec == 'o' && phar->length == 7)
		phar->str = ft_itoa_base((va_arg(ap, long)), 8, 0);
	if (phar->spec == 'O')
		phar->str = ft_itoa_base(va_arg(ap, unsigned long long), 8, 0);
	return (1);
}

int		save_p(t_prf *phar, va_list ap)
{
	if (phar->spec == 'p')
		phar->str = ft_strjoin("0x", ft_itoa_base(va_arg(ap, long long),
				16, 0));
	return (1);
}
