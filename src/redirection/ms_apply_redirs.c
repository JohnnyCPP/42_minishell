/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_apply_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_apply_heredoc(t_redir *redir)
{
	redir->new_fd = ms_heredoc(redir->filename);
	if (redir->new_fd == FAIL)
		return (EXIT_FAILURE);
	redir->old_fd = dup(STDIN_FILENO);
	dup2(redir->new_fd, STDIN_FILENO);
	return (EXIT_SUCCESS);
}

static	int	ms_apply_apnd(t_redir *redir)
{
	int	flags;

	flags = O_WRONLY | O_CREAT | O_APPEND;
	redir->new_fd = open(redir->filename, flags, MODE_RW);
	if (redir->new_fd == FAIL)
	{
		perror(redir->filename);
		return (EXIT_FAILURE);
	}
	redir->old_fd = dup(STDOUT_FILENO);
	dup2(redir->new_fd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

static	int	ms_apply_out(t_redir *redir)
{
	int	flags;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	redir->new_fd = open(redir->filename, flags, MODE_RW);
	if (redir->new_fd == FAIL)
	{
		perror(redir->filename);
		return (EXIT_FAILURE);
	}
	redir->old_fd = dup(STDOUT_FILENO);
	dup2(redir->new_fd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

static	int	ms_apply_in(t_redir *redir)
{
	int	flags;

	flags = O_RDONLY;
	redir->new_fd = open(redir->filename, flags);
	if (redir->new_fd == FAIL)
	{
		perror(redir->filename);
		return (EXIT_FAILURE);
	}
	redir->old_fd = dup(STDIN_FILENO);
	dup2(redir->new_fd, STDIN_FILENO);
	return (EXIT_SUCCESS);
}

int	ms_apply_redirs(t_redir_list *list)
{
	t_redir	*current;
	int		status;
	int		i;

	status = EXIT_SUCCESS;
	i = 0;
	while (i < list->length)
	{
		current = &list->redirs[i];
		if (current->type == T_REDIR_IN)
			status = ms_apply_in(current);
		else if (current->type == T_REDIR_OUT)
			status = ms_apply_out(current);
		else if (current->type == T_REDIR_APND)
			status = ms_apply_apnd(current);
		else if (current->type == T_HEREDOC)
			status = ms_apply_heredoc(current);
		i ++;
		if (status == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
