/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_valid_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ms_get_valid_path(t_shell *shell, const char *lexeme, int *error_code)
{
	char	*cmd_path;

	cmd_path = ms_get_path(shell, lexeme);
	*error_code = ms_is_path_valid(cmd_path, lexeme);
	if (*error_code)
	{
		free(cmd_path);
		return (NULL);
	}
	return (cmd_path);
}
