/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_has_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_has_pipe(t_token_list *list)
{
	t_token	*current;

	current = list->head;
	while (current)
	{
		if (current->type == T_PIPE)
			return (TRUE);
		current = current->next;
	}
	return (FALSE);
}
