/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sp_he_mi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:23:09 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/17 16:25:09 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		make_space(t_prf *phar)
{
	if (phar->flags[4] == 1 && phar->flags[2] != 1 &&
		phar->str[0] != '+' && phar->str[0] != '-' && phar->spec != 'p')
	{
		if (phar->spec == 'd' || phar->spec == 'i' || phar->spec == 'D' ||
				phar->spec == 'O' || phar->spec == 'o' || phar->spec == 'p' ||
				phar->spec == 'u' || phar->spec == 'U')
			phar->str = ft_strjoin(" ", phar->str);
	}
	return (1);
}

int		make_hesh(t_prf *phar)
{
	if (phar->flags[2] == 1)
		if ((phar->spec == 'o' || phar->spec == 'O') &&
				(phar->str[0] != '0' || (phar->str[0] == '0' &&
										phar->str[1] != '\0')))
			phar->str = ft_strjoin("0", phar->str);
	if (phar->flags[2] == 1 && (phar->str[0] != '0' && phar->str[1] != '\0'))
	{
		if (phar->spec == 'x')
			phar->str = ft_strjoin("0x", phar->str);
		if (phar->spec == 'X')
			phar->str = ft_strjoin("0X", phar->str);
	}
	return (1);
}

int		make_plus(t_prf *phar)
{
	if (phar->flags[1] == 1 && phar->str[0] != '-' &&
			(phar->spec == 'd' || phar->spec == 'i' || phar->spec == 'D'))
		phar->str = ft_strjoin("+", phar->str);
	return (0);
}
