/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_revert_redirs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_revert_redirs(t_redir_list *list)
{
	if (list->stdin != FAIL)
	{
		dup2(list->stdin, STDIN_FILENO);
		close(list->stdin);
	}
	if (list->stdout != FAIL)
	{
		dup2(list->stdout, STDOUT_FILENO);
		close(list->stdout);
	}
}
