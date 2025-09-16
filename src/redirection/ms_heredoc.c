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

int	ms_heredoc(char *delimiter)
{
	char	*line;
	int		pipe_fd[PIPE_FD_AMOUNT];

	if (pipe(pipe_fd) == FAIL)
		return (EXIT_FAILURE);
	while (TRUE)
	{
		line = readline(HEREDOC_PROMPT);
		if (!line)
			break ;
		if (!ft_strcmp(line, delimiter))
		{
			free(line);
			break ;
		}
		write(pipe_fd[PIPE_WRITE_END], line, ft_strlen(line));
		write(pipe_fd[PIPE_WRITE_END], "\n", 1);
		free(line);
	}
	close(pipe_fd[PIPE_WRITE_END]);
	return (pipe_fd[PIPE_READ_END]);
}
