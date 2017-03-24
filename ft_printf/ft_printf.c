/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:37:23 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 18:47:33 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		save_str(const char *str, t_prf *phar, va_list ap)
{
	phar->spec = str[0];
	if (phar->spec == 'd' || phar->spec == 'i' || phar->spec == 'D')
		save_d(phar, ap);
	else if (phar->spec == 'x' || phar->spec == 'X')
		save_x(phar, ap);
	else if (phar->spec == 'O' || phar->spec == 'o')
		save_o(phar, ap);
	else if (phar->spec == 'p')
		save_p(phar, ap);
	else if (phar->spec == 'u' || phar->spec == 'U')
		save_u(phar, ap);
	else if (phar->spec == 's' || phar->spec == 'S')
		save_s(phar, ap);
	else if (phar->spec == 'b')
		save_b(phar, ap);
	else
		save_c(phar, ap);
	if (!phar->str)
		return (0);
	if (phar->str[0] == '\0' && phar->str[1] == '\0')
		phar->str[0] = '\301';
	return (1);
}

void	write_str(t_prf *phar)
{
	int i;

	i = 0;
	if (!phar->str)
		return ;
	while (phar->str[i] != '\0')
	{
		if (phar->str[i] == '\301')
			write(1, "\0", 1);
		else
			ft_putchar_fd(phar->str[i], 1);
		i++;
	}
}

int		make_all(t_prf *phar)
{
	if (phar->str[0] != '\301')
	{
		if (phar->pr > 0)
			make_prec(phar);
		make_plus(phar);
		if (phar->spec != 'u' && phar->spec != 'o')
			make_space(phar);
		make_hesh(phar);
	}
	make_width(phar);
	kostuli(phar);
	return (1);
}

int		phars(const char *str, va_list ap, int *count)
{
	int		i;
	t_prf	phar;
	int		a;

	i = 0;
	__builtin_bzero(&phar, sizeof(phar));
	while ((a = test_symb(str[i])) > 0)
	{
		if (a == 1)
			i = i + flags(&str[i], &phar);
		if (a == 4)
			i = i + width(&str[i], &phar, ap);
		if (a == 3)
			i = i + 1 + prec(&str[i + 1], &phar, ap);
		if (a == 2)
			i = i + length(&str[i], &phar);
		if (a == 5)
			return (i);
	}
	i = i + save_str(&str[i], &phar, ap);
	make_all(&phar);
	if (phar.str)
		write_str(&phar);
	*count += ft_strlen(phar.str);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		while (format[i] == '%')
			i = i + phars(&format[i + 1], ap, &count) + 1;
		if (format[i] == '{')
			i = i + color(&format[i]);
		if (format[i] != '\0')
		{
			ft_putchar_fd(format[i], 1);
			count++;
			i++;
		}
	}
	va_end(ap);
	return (count);
}
