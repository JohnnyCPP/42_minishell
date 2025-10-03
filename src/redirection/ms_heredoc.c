/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_restore_oldhndlr(struct sigaction *old, int *in, int *out)
{
	sigaction(SIGINT, old, NULL);
	rl_event_hook = NULL;
	rl_done = READLINE_NOT_FINISHED;
	dup2(*in, STDIN_FILENO);
	dup2(*out, STDOUT_FILENO);
	close(*in);
	close(*out);
	*in = NO_FILE_DESCRIPTOR;
	*out = NO_FILE_DESCRIPTOR;
}

void	ms_save_oldhndlr(struct sigaction *sa, int *i, int *o, t_redir_list *l)
{
	sigaction(SIGINT, NULL, sa);
	ms_set_heredoc_handler();
	*i = dup(STDIN_FILENO);
	*o = dup(STDOUT_FILENO);
	dup2(l->stdin, STDIN_FILENO);
	dup2(l->stdout, STDOUT_FILENO);
}

static	int	ms_parse_heredoc_line(char *line, char *delimiter, int *pipe)
{
	if (!line)
		return (HEREDOC_END);
	if (ms_get_signal() == SIGINT)
	{
		free(line);
		return (HEREDOC_END);
	}
	if (!ft_strcmp(line, delimiter))
	{
		free(line);
		return (HEREDOC_END);
	}
	write(pipe[PIPE_WRITE_END], line, ft_strlen(line));
	write(pipe[PIPE_WRITE_END], "\n", 1);
	free(line);
	return (HEREDOC_CONTINUE);
}

int	ms_heredoc(t_redir_list *list, char *delimiter)
{
	struct sigaction	old_sigint;
	char				*line;
	int					pipe_fd[PIPE_FD_AMOUNT];
	int					old_stdin;
	int					old_stdout;

	if (pipe(pipe_fd) == FAIL)
		return (EXIT_FAILURE);
	old_stdin = NO_FILE_DESCRIPTOR;
	old_stdout = NO_FILE_DESCRIPTOR;
	ms_save_oldhndlr(&old_sigint, &old_stdin, &old_stdout, list);
	while (ms_get_signal() == SIGNAL_RESET)
	{
		line = readline(HEREDOC_PROMPT);
		if (ms_parse_heredoc_line(line, delimiter, pipe_fd) == HEREDOC_END)
			break ;
	}
	ms_restore_oldhndlr(&old_sigint, &old_stdin, &old_stdout);
	close(pipe_fd[PIPE_WRITE_END]);
	return (pipe_fd[PIPE_READ_END]);
}
