/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_to_heredocs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_get_hdoc(t_heredoc_list *l, int hdoc, t_token *d, t_stdio stdio)
{
	if (d->type != T_WORD || !d->lexeme)
		return (FALSE);
	l->heredocs[hdoc].delimiter = ft_strdup(d->lexeme);
	l->heredocs[hdoc].fd = ms_heredoc(l->heredocs[hdoc].delimiter, stdio);
	if (l->heredocs[hdoc].fd == NO_FILE_DESCRIPTOR)
		return (FALSE);
	return (TRUE);
}

int	ms_to_heredocs(t_token_list *cmd, t_heredoc_list *hdoc)
{
	t_token	*current;
	t_stdio	stdio;
	int		heredoc;
	int		token;

	if (!cmd || !cmd->head)
		return (FALSE);
	current = cmd->head;
	stdio.stdin = STDIN_FILENO;
	stdio.stdout = STDOUT_FILENO;
	heredoc = 0;
	token = 0;
	while (token < cmd->length && heredoc < hdoc->length)
	{
		if (current->type == T_HEREDOC && current->next)
		{
			if (!ms_get_hdoc(hdoc, heredoc, current->next, stdio))
				return (FALSE);
			heredoc ++;
		}
		current = current->next;
		token ++;
	}
	return (TRUE);
}
