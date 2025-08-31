/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:02:01 by cvicol            #+#    #+#             */
/*   Updated: 2025/08/22 17:39:30 by cvicol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

// TODO:
// int is_builtin(char *cmd)
// void execute_builtin(t_list *tokens)
// void execute_external(t_list *tokens)

t_token_list	*ms_get_tokens(const char *input)
{
	t_token_list	*list;
	int				i;

	list = ms_create_token_list();
	if (!list || !input)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (ms_iswhitespace(input[i]))
			i ++;
		else if (input[i] == '|')
			i += ms_analyze_pipe(list);
		else if (ms_isredirection(input[i]))
			i += (int) ms_analyze_redirection(&input[i], list);
		else
			i += ms_analyze_word(&input[i], list);
	}
	return (list);
}
