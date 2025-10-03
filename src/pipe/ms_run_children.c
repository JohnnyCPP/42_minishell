/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_children.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_run_children(t_shell *shell, int i, int *prev, int *next)
{
	shell->child_stdin = dup(STDIN_FILENO);
	shell->child_stdout = dup(STDOUT_FILENO);
	if (i > 0)
	{
		dup2(prev[PIPE_READ_END], STDIN_FILENO);
		close(prev[PIPE_READ_END]);
		close(prev[PIPE_WRITE_END]);
	}
	if (i < shell->pipeline->length - 1)
	{
		dup2(next[PIPE_WRITE_END], STDOUT_FILENO);
		close(next[PIPE_READ_END]);
		close(next[PIPE_WRITE_END]);
	}
	ms_delete_tokens(&shell->tokens);
	shell->tokens = shell->pipeline->commands[i];
	if (ms_is_builtin(shell->tokens->head->lexeme))
		exit(ms_run_builtin(shell, TRUE));
	exit(ms_run_external(shell, TRUE));
}
