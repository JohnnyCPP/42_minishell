/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_path_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_is_path_valid(char *cmd_path, const char *lexeme)
{
	struct stat	stats;
	int			exists;
	int			is_directory;
	int			is_executable;

	if (!cmd_path)
		return (ms_cmd_notfound(lexeme));
	exists = !stat(cmd_path, &stats);
	if (!exists)
		return (ms_file_not_found(lexeme));
	is_directory = !stat(cmd_path, &stats) && S_ISDIR(stats.st_mode);
	is_executable = !access(cmd_path, X_OK);
	if (is_directory)
		return (ms_is_a_directory(lexeme));
	if (!is_executable)
		return (ms_permission_denied(lexeme));
	return (STD_RET_OK);
}
