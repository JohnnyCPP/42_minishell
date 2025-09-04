/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_list_clear(t_list **list, void (*function)(void *))
{
	t_list	*pointer;
	t_list	*auxiliar;

	if (!list || !function)
		return ;
	pointer = *list;
	auxiliar = pointer->next_node;
	while (pointer)
	{
		(*function)(pointer->data);
		free(pointer);
		pointer = auxiliar;
		if (auxiliar)
			auxiliar = auxiliar->next_node;
	}
	*list = (void *) 0;
}
