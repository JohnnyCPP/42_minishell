/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_heredoc_lists.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	void	ms_free_heredocs(t_heredoc_list *list)
{
	int	heredoc;

	if (!list)
		return ;
	heredoc = 0;
	while (heredoc < list->length)
	{
		free(list->heredocs[heredoc].delimiter);
		list->heredocs[heredoc].delimiter = NULL;
		close(list->heredocs[heredoc].fd);
		heredoc ++;
	}
	if (list->heredocs)
		free(list->heredocs);
	list->heredocs = NULL;
}

void	ms_free_heredoc_lists(t_shell *shell)
{
	int	len;
	int	list;

	len = shell->pipeline->length;
	list = 0;
	while (list < len)
	{
		ms_free_heredocs(&shell->pipeline->hdoc_lists[list]);
		list ++;
	}
	free(shell->pipeline->hdoc_lists);
	shell->pipeline->hdoc_lists = NULL;
}
