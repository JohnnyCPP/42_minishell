/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_run_command(t_shell *shell)
{
	char	*lexeme;

	lexeme = shell->tokens->head->lexeme;
	if (ms_is_builtin(lexeme))
		shell->exit_code = ms_run_builtin(shell, lexeme);
	else
		shell->exit_code = ms_run_external(shell, lexeme);
}
