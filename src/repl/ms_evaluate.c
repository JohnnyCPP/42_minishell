/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_evaluate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_evaluate(t_shell *shell)
{
	if (!shell)
		return ;
	shell->tokens = ms_get_tokens(shell->input);
	if (!shell->tokens || !shell->tokens->head)
		return ;
	add_history(shell->input);
	ms_add_history(shell);
	if (!ms_are_tokens_valid(shell->tokens))
	{
		ms_delete_tokens(&shell->tokens);
		return ;
	}
	ms_strip_quotes(shell);
	ms_run_command(shell);
	ms_delete_tokens(&shell->tokens);
}
