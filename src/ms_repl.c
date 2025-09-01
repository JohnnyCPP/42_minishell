/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_repl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by cvicol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/**
 * TODO: 1. clear single and double quotes from tokens
 *       2. execution of built-in commands
 *       3. inspection of $PATH for command lookup
 *       4. execution of system commands
 */
static	void	ms_evaluate(const char *input)
{
	t_token_list	*list;

	add_history(input);
	list = ms_get_tokens(input);
	if (!list)
		return ;
	if (!ms_are_tokens_valid(list))
	{
		ms_delete_list(&list);
		return ;
	}
	ms_strip_quotes(list);
	ms_print_tokens(list);
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
		if (ms_get_signal() == SIGINT)
		{
			free(input);
			continue ;
		}
		if (input[0] != '\0')
			ms_evaluate(input);
		free(input);
	}
}
