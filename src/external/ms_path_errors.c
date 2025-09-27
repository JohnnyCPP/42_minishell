/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_path_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_cmd_notfound(const char *cmd)
{
	char	*error;

	error = ms_concat(ERR_CMD_NOTFOUND_HEAD, cmd, ERR_CMD_NOTFOUND_TAIL);
	ms_puterr(error);
	free(error);
	return (STD_RET_NOTFOUND);
}

int	ms_file_not_found(const char *cmd)
{
	char	*error;

	error = ms_concat(ERR_EXECVE_HEAD, cmd, ERR_EXECVE_TAIL);
	ms_puterr(error);
	free(error);
	return (STD_RET_NOTFOUND);
}

int	ms_is_a_directory(const char *cmd)
{
	char	*error;

	error = ms_concat(ERR_EXECVE_HEAD, cmd, ERR_IS_DIRECTORY);
	ms_puterr(error);
	free(error);
	return (STD_RET_CANTEXEC);
}

int	ms_permission_denied(const char *cmd)
{
	char	*error;

	error = ms_concat(ERR_EXECVE_HEAD, cmd, ERR_PERM_DENIED);
	ms_puterr(error);
	free(error);
	return (STD_RET_CANTEXEC);
}
