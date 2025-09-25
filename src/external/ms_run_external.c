/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_external.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_execute_parent(pid_t child, char *cmd_path, char **argv)
{
	int	child_status;

	waitpid(child, &child_status, WAIT_FOR_CHILD);
	free(cmd_path);
	ms_free_strings(argv);
	return (WEXITSTATUS(child_status));
}

static	int	ms_execute_child(t_shell *shell, char *cmd_path, char **argv)
{
	execve(cmd_path, argv, shell->env);
	perror(ERR_EXECVE);
	return (STD_RET_CANTEXEC);
}

static	int	ms_child_failed(char *cmd_path, char **argv)
{
	free(cmd_path);
	ms_free_strings(argv);
	return (STD_RET_KO);
}

static	int	ms_execute_cmd(t_shell *shell, char *cmd_path)
{
	char	**argv;
	pid_t	child;

	argv = ms_to_argv(shell->tokens);
	if (!argv)
	{
		free(cmd_path);
		return (STD_RET_KO);
	}
	child = fork();
	if (child == FAIL)
		return (ms_child_failed(cmd_path, argv));
	if (child == PROC_CHILD)
		return (ms_execute_child(shell, cmd_path, argv));
	return (ms_execute_parent(child, cmd_path, argv));
}

int	ms_run_external(t_shell *shell, const char *lexeme, int is_child)
{
	t_redir_list	*list;
	char			*cmd_path;
	int				error_code;
	int				exit_status;

	list = ms_get_redirs(shell);
	if (!list)
	{
		if (is_child)
			ms_free_childres(shell);
		return (STD_RET_KO);
	}
	if (ms_apply_redirs(list) == EXIT_FAILURE)
	{
		if (is_child)
			ms_free_childres(shell);
		return (ms_free_redirs(&list));
	}
	error_code = 0;
	cmd_path = ms_get_valid_path(shell, lexeme, &error_code);
	if (!cmd_path)
	{
		if (is_child)
			ms_free_childres(shell);
		return (error_code);
	}
	exit_status = ms_execute_cmd(shell, cmd_path);
	ms_free_redirs(&list);
	if (is_child)
		ms_free_childres(shell);
	return (exit_status);
}
