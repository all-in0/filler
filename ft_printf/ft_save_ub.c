/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_ub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:14:42 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 19:08:16 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		save_u(t_prf *phar, va_list ap)
{
	if (phar->spec == 'u' && phar->length == 0)
		phar->str = ft_ultoa(va_arg(ap, unsigned int));
	if (phar->spec == 'u' && phar->length == 1)
		phar->str = ft_ultoa((unsigned char)va_arg(ap, unsigned int));
	if (phar->spec == 'u' && phar->length == 2)
		phar->str = ft_ultoa((unsigned short int)va_arg(ap, unsigned int));
	if (phar->spec == 'u' && phar->length == 3)
		phar->str = ft_ultoa(va_arg(ap, unsigned long long));
	if (phar->spec == 'u' && phar->length == 4)
		phar->str = ft_ultoa(va_arg(ap, unsigned long int));
	if (phar->spec == 'u' && phar->length == 5)
		phar->str = ft_ultoa((uintmax_t)va_arg(ap, uintmax_t));
	if (phar->spec == 'u' && phar->length == 6)
		phar->str = ft_ultoa((size_t)va_arg(ap, size_t));
	if (phar->spec == 'u' && phar->length == 7)
		phar->str = ft_ultoa(va_arg(ap, long));
	if (phar->spec == 'U')
		phar->str = ft_ultoa(va_arg(ap, unsigned long long));
	return (1);
}

int		save_b(t_prf *phar, va_list ap)
{
	char			bits[8];
	int				nb;
	int				count;
	char			z;
	unsigned char	octet;

	phar->str = (char *)malloc(sizeof(phar->str) * 9);
	octet = va_arg(ap, unsigned int);
	nb = octet;
	count = 0;
	while (count < 8)
	{
		bits[count] = nb % 2;
		nb = nb / 2;
		count++;
	}
	nb = -1;
	while (count - 1 >= 0)
	{
		z = bits[count - 1] + 48;
		phar->str[++nb] = z;
		count--;
	}
	phar->str[8] = '\0';
	return (1);
}
