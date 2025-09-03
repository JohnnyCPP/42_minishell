/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_run_builtin(t_token_list *list)
{
	if (!list || !list->head || !list->head->lexeme)
		return (STD_RET_KO);
	if (!ft_strcmp(list->head->lexeme, CMD_CD))
		return (ms_cd(list));
	if (!ft_strcmp(list->head->lexeme, CMD_ECHO))
		return (ms_echo(list));
	if (!ft_strcmp(list->head->lexeme, CMD_ENV))
		return (ms_env(list));
	if (!ft_strcmp(list->head->lexeme, CMD_EXIT))
		return (ms_exit(list));
	if (!ft_strcmp(list->head->lexeme, CMD_EXPORT))
		return (ms_export(list));
	if (!ft_strcmp(list->head->lexeme, CMD_PWD))
		return (ms_pwd(list));
	if (!ft_strcmp(list->head->lexeme, CMD_UNSET))
		return (ms_unset(list));
	return (STD_RET_KO);
}
