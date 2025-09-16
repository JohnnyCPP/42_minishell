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
	t_redir	*current;
	int		restore;
	int		i;

	i = 0;
	while (i < list->length)
	{
		current = &list->redirs[i];
		if (current->old_fd != FAIL)
		{
			if (current->type == T_REDIR_IN || current->type == T_HEREDOC)
				restore = STDIN_FILENO;
			else
				restore = STDOUT_FILENO;
			dup2(current->old_fd, restore);
			close(current->old_fd);
		}
		if (current->new_fd != FAIL)
			close(current->new_fd);
		i ++;
	}
}
