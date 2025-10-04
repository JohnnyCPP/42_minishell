/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_heredocs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_iterate_tokens(t_shell *shell, int cmd)
{
	t_pipeline		*p;
	t_token_list	*command;
	int				len;

	p = shell->pipeline;
	command = p->commands[cmd];
	len = ms_count_heredocs(command);
	if (len)
		p->hdoc_lists[cmd].heredocs = ft_calloc(len, sizeof(t_heredoc));
	else
		p->hdoc_lists[cmd].heredocs = NULL;
	if (len && !p->hdoc_lists[cmd].heredocs)
		return (EXIT_FAILURE);
	p->hdoc_lists[cmd].length = len;
	if (!ms_to_heredocs(command, &p->hdoc_lists[cmd]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static	int	ms_iterate_commands(t_shell *shell)
{
	int	cmd;

	cmd = 0;
	while (cmd < shell->pipeline->length)
	{
		if (ms_iterate_tokens(shell, cmd) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		cmd ++;
	}
	return (EXIT_SUCCESS);
}

int	ms_get_heredocs(t_shell *shell)
{
	if (ms_allocate_heredoc_lists(shell) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (ms_iterate_commands(shell) == EXIT_FAILURE)
	{
		ms_free_heredoc_lists(shell);
		ms_free_pipeline(&shell->pipeline);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
