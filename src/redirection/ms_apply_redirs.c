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

static	int	ms_apply_hdoc(t_shell *sh, t_redir_list *lst, int chld, t_redir *rd)
{
	t_stdio	stdio;
	int		heredoc_fd;

	stdio.stdin = lst->stdin;
	stdio.stdout = lst->stdout;
	if (chld)
	{
		heredoc_fd = sh->hdoc_list->heredocs[sh->curr_hdoc].fd;
		sh->curr_hdoc ++;
	}
	else
		heredoc_fd = ms_heredoc(rd->filename, stdio);
	if (heredoc_fd == NO_FILE_DESCRIPTOR)
		return (EXIT_FAILURE);
	dup2(heredoc_fd, STDIN_FILENO);
	close(heredoc_fd);
	return (EXIT_SUCCESS);
}

static	int	ms_apply_apnd(t_redir *redir)
{
	int	flags;
	int	file_fd;

	flags = O_WRONLY | O_CREAT | O_APPEND;
	file_fd = open(redir->filename, flags, MODE_RW);
	if (file_fd == FAIL)
	{
		perror(redir->filename);
		return (EXIT_FAILURE);
	}
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
	return (EXIT_SUCCESS);
}

static	int	ms_apply_out(t_redir *redir)
{
	int	flags;
	int	file_fd;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	file_fd = open(redir->filename, flags, MODE_RW);
	if (file_fd == FAIL)
	{
		perror(redir->filename);
		return (EXIT_FAILURE);
	}
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
	return (EXIT_SUCCESS);
}

static	int	ms_apply_in(t_redir *redir)
{
	int	flags;
	int	file_fd;

	flags = O_RDONLY;
	file_fd = open(redir->filename, flags);
	if (file_fd == FAIL)
	{
		perror(redir->filename);
		return (EXIT_FAILURE);
	}
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
	return (EXIT_SUCCESS);
}

int	ms_apply_redirs(t_shell *shell, t_redir_list *list, int is_child)
{
	t_redir	*current;
	int		status;
	int		i;

	ms_save_original_fds(shell, list, is_child);
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
			status = ms_apply_hdoc(shell, list, is_child, current);
		i ++;
		if (status == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
