/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:21:18 by vnakonec          #+#    #+#             */
/*   Updated: 2017/03/24 13:22:24 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "ft_printf/ft_printf.h"
#include <stdbool.h>

typedef struct		s_fil
{
	int				pl;
	int				x;
	int				y;
	int				fig_y;
	int				fig_x;
	char 			*fig;
	char			spec;
	char			*map;
}					t_fil;

#endif