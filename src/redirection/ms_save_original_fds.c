/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_save_original_fds.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_save_original_fds(t_shell *shell, t_redir_list *list, int is_child)
{
	if (is_child)
	{
		list->stdin = shell->child_stdin;
		list->stdout = shell->child_stdout;
		shell->child_stdin = NO_FILE_DESCRIPTOR;
		shell->child_stdout = NO_FILE_DESCRIPTOR;
	}
	else
	{
		list->stdin = dup(STDIN_FILENO);
		list->stdout = dup(STDOUT_FILENO);
	}
}
