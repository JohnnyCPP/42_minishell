/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_repl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/**
 * TODO: 1. persist history
 *       2. redirections and pipes
 */
static	void	ms_run_command(t_shell *shell)
{
	char	*lexeme;

	lexeme = shell->tokens->head->lexeme;
	if (ms_is_builtin(lexeme))
		shell->exit_code = ms_run_builtin(shell, lexeme);
	else
		shell->exit_code = ms_run_external(shell, lexeme);
}

static	void	ms_evaluate(t_shell *shell)
{
	if (!shell)
		return ;
	shell->tokens = ms_get_tokens(shell->input);
	if (!shell->tokens || !shell->tokens->head)
		return ;
	add_history(shell->input);
	if (!ms_are_tokens_valid(shell->tokens))
	{
		ms_delete_tokens(&shell->tokens);
		return ;
	}
	ms_strip_quotes(shell);
	ms_run_command(shell);
	ms_delete_tokens(&shell->tokens);
}

static	void	ms_exitshell(void)
{
	rl_clear_history();
	printf(MSG_EXIT_SHELL);
}

void	ms_read_loop(t_shell *shell)
{
	while (TRUE)
	{
		ms_set_signal(SIGNAL_RESET);
		shell->input = readline(PROMPT);
		if (!shell->input)
		{
			ms_exitshell();
			break ;
		}
		if (shell->input[0] != '\0')
		{
			ms_evaluate(shell);
			continue ;
		}
		if (ms_get_signal() == SIGINT)
		{
			free(shell->input);
			continue ;
		}
		free(shell->input);
	}
}
