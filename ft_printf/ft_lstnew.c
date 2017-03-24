/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnakonec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:24:59 by vnakonec          #+#    #+#             */
/*   Updated: 2016/12/01 15:35:54 by vnakonec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "./ft_printf.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->next = 0;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	if ((new->content = (void *)malloc(content_size)) == 0)
		return (0);
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}
