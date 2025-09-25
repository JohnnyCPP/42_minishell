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

static	void	ms_handle_heredoc_sigint(int signal)
{
	ms_set_signal(signal);
}

static	int	ms_heredoc_event_hook(void)
{
	if (ms_get_signal() == SIGINT)
		rl_done = READLINE_FINISHED;
	return (EXIT_SUCCESS);
}

static	void	ms_set_heredoc_handler(void)
{
	struct sigaction	new_sigint;

	new_sigint.sa_handler = ms_handle_heredoc_sigint;
	sigemptyset(&new_sigint.sa_mask);
	new_sigint.sa_flags = 0;
	sigaction(SIGINT, &new_sigint, NULL);
	ms_set_signal(SIGNAL_RESET);
	rl_event_hook = ms_heredoc_event_hook;
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

int	ms_heredoc(char *delimiter)
{
	struct sigaction	old_sigint;
	char				*line;
	int					pipe_fd[PIPE_FD_AMOUNT];

	if (pipe(pipe_fd) == FAIL)
		return (EXIT_FAILURE);
	sigaction(SIGINT, NULL, &old_sigint);
	ms_set_heredoc_handler();
	while (ms_get_signal() == SIGNAL_RESET)
	{
		line = readline(HEREDOC_PROMPT);
		if (ms_parse_heredoc_line(line, delimiter, pipe_fd) == HEREDOC_END)
			break ;
	}
	sigaction(SIGINT, &old_sigint, NULL);
	rl_event_hook = NULL;
	rl_done = READLINE_NOT_FINISHED;
	close(pipe_fd[PIPE_WRITE_END]);
	return (pipe_fd[PIPE_READ_END]);
}
