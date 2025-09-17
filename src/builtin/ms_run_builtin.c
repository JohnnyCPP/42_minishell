/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_find_builtin(t_shell *shell, const char *lexeme)
{
	if (!shell->tokens || !shell->tokens->head || !lexeme)
		return (STD_RET_KO);
	if (!ft_strcmp(lexeme, CMD_CD))
		return (ms_cd(shell));
	if (!ft_strcmp(lexeme, CMD_ECHO))
		return (ms_echo(shell));
	if (!ft_strcmp(lexeme, CMD_ENV))
		return (ms_env(shell));
	if (!ft_strcmp(lexeme, CMD_EXIT))
		return (ms_exit(shell));
	if (!ft_strcmp(lexeme, CMD_EXPORT))
		return (ms_export(shell));
	if (!ft_strcmp(lexeme, CMD_PWD))
		return (ms_pwd());
	if (!ft_strcmp(lexeme, CMD_UNSET))
		return (ms_unset(shell));
	return (STD_RET_KO);
}

int	ms_run_builtin(t_shell *shell, const char *lexeme)
{
	t_redir_list	*list;
	int				status_code;

	list = ms_get_redirs(shell);
	if (!list)
		return (STD_RET_KO);
	if (ms_apply_redirs(list) == EXIT_FAILURE)
		return (ms_free_redirs(&list));
	status_code = ms_find_builtin(shell, lexeme);
	ms_free_redirs(&list);
	return (status_code);
}
