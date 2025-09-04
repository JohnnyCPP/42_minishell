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
 * TODO: 1. execution of built-in commands
 *       2. inspection of $PATH for command lookup
 *       3. execution of system commands
 *       4. redirections and pipes
 *       5. persist history
 */
static	void	ms_run_command(t_token_list *list)
{
	int	exit_status;

	(void) exit_status;
	if (ms_is_builtin(list->head->lexeme))
		exit_status = ms_run_builtin(list);
}

static	void	ms_evaluate(const char *input)
{
	t_token_list	*list;

	list = ms_get_tokens(input);
	if (!list || !list->head)
		return ;
	add_history(input);
	if (!ms_are_tokens_valid(list))
	{
		ms_delete_list(&list);
		return ;
	}
	ms_strip_quotes(list);
	ms_print_tokens(list);
	ms_run_command(list);
	ms_delete_list(&list);
}

static	void	ms_exitshell(void)
{
	rl_clear_history();
	printf(MSG_EXIT_SHELL);
}

void	ms_read_loop(void)
{
	char	*input;

	while (TRUE)
	{
		ms_set_signal(SIGNAL_RESET);
		input = readline(PROMPT);
		if (!input)
		{
			ms_exitshell();
			break ;
		}
		if (input[0] != '\0')
		{
			ms_evaluate(input);
			continue ;
		}
		if (ms_get_signal() == SIGINT)
		{
			free(input);
			continue ;
		}
		free(input);
	}
}
