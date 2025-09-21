/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_run_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_wait_children(t_pipeline *pipeline, int *status, pid_t **children)
{
	int	i;

	i = 0;
	while (i < pipeline->length)
	{
		if (waitpid((*children)[i], status, NO_OPTIONS) == FAIL)
			perror(ERR_WAITPID);
		i ++;
	}
	free(*children);
	*children = NULL;
}

void	ms_swap_pipes(int i, t_pipeline *pipeline, int *prev, int *next)
{
	if (i > 0)
	{
		close(prev[PIPE_READ_END]);
		close(prev[PIPE_WRITE_END]);
	}
	if (i < pipeline->length - 1)
	{
		prev[PIPE_READ_END] = next[PIPE_READ_END];
		prev[PIPE_WRITE_END] = next[PIPE_WRITE_END];
	}
}

static	void	ms_run_children(t_shell *shell, int i, int *prev, int *next)
{
	if (i > 0)
	{
		dup2(prev[PIPE_READ_END], STDIN_FILENO);
		close(prev[PIPE_READ_END]);
		close(prev[PIPE_WRITE_END]);
	}
	if (i < shell->pipeline->length - 1)
	{
		dup2(next[PIPE_WRITE_END], STDOUT_FILENO);
		close(next[PIPE_READ_END]);
		close(next[PIPE_WRITE_END]);
	}
	shell->tokens = shell->pipeline->commands[i];
	if (ms_is_builtin(shell->tokens->head->lexeme))
		exit(ms_run_builtin(shell, shell->tokens->head->lexeme));
	else
		exit(ms_run_external(shell, shell->tokens->head->lexeme));
}

int	ms_new_pipe(int i, int *next, t_pipeline *pipeline, pid_t **children)
{
	if (i < pipeline->length - 1)
	{
		if (pipe(next) == FAIL)
		{
			perror(ERR_PIPE);
			free(*children);
			*children = NULL;
			return (STD_RET_KO);
		}
	}
	return (STD_RET_OK);
}

int	ms_run_pipeline(t_shell *shell, t_pipeline *pipeline)
{
	pid_t	*children;
	int		pipe_prev[PIPE_FD_AMOUNT];
	int		pipe_next[PIPE_FD_AMOUNT];
	int		status;
	int		i;

	pipe_prev[PIPE_READ_END] = NO_FILE_DESCRIPTOR;
	pipe_prev[PIPE_WRITE_END] = NO_FILE_DESCRIPTOR;
	children = (pid_t *) ft_calloc(pipeline->length, sizeof(pid_t));
	if (!children)
		return (STD_RET_KO);
	i = 0;
	while (i < pipeline->length)
	{
		if (ms_new_pipe(i, pipe_next, pipeline, &children) == STD_RET_KO)
			return (STD_RET_KO);
		children[i] = fork();
		if (children[i] == PROC_CHILD)
			ms_run_children(shell, i, pipe_prev, pipe_next);
		ms_swap_pipes(i, pipeline, pipe_prev, pipe_next);
		i ++;
	}
	ms_wait_children(pipeline, &status, &children);
	return (WEXITSTATUS(status));
}
