/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_list_map(t_list *list, void *(*f)(void *), void (*d)(void *))
{
	t_list	*pointer;
	t_list	*ptr_first_node;

	if (!list || !f || !d)
		return ((void *) 0);
	ptr_first_node = (void *) 0;
	while (list)
	{
		pointer = ft_list_new((*f)(list->data));
		if (!pointer)
		{
			ft_list_clear(&ptr_first_node, d);
			return ((void *) 0);
		}
		ft_list_add_back(&ptr_first_node, pointer);
		list = list->next_node;
	}
	return (pointer);
}
