/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_count_heredocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_count_heredocs(t_token_list *list)
{
	t_token	*current;
	int		heredocs;
	int		i;

	if (!list || !list->head)
		return (0);
	current = list->head;
	heredocs = 0;
	i = 0;
	while (i < list->length && current)
	{
		if (current->type == T_HEREDOC)
			heredocs ++;
		i ++;
		current = current->next;
	}
	return (heredocs);
}
