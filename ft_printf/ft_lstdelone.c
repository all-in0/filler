/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:28:10 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/01 17:14:54 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;

	new = *alst;
	del(new->content, new->content_size);
	free(*alst);
	*alst = 0;
}
