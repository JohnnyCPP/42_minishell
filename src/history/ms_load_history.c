/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_load_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	void	ms_read_existing_history(char *next_line, const int fd)
{
	int	strlen;
	int	end;

	while (next_line)
	{
		strlen = ft_strlen(next_line);
		end = strlen - 1;
		if (next_line[end] == '\n')
			next_line[end] = '\0';
		add_history(next_line);
		free(next_line);
		next_line = ft_gnl(fd);
	}
}

static	int	ms_history_exists(int *fd, char *history_path)
{
	*fd = open(history_path, O_RDONLY);
	if (*fd == DOES_NOT_EXIST)
	{
		free(history_path);
		return (FALSE);
	}
	return (TRUE);
}

void	ms_load_history(t_shell *shell)
{
	char	*history_path;
	char	*next_line;
	int		fd;

	history_path = ms_get_history_path(shell);
	if (!history_path)
		return ;
	if (!ms_history_exists(&fd, history_path))
		return ;
	next_line = ft_gnl(fd);
	ms_read_existing_history(next_line, fd);
	close(fd);
	free(history_path);
}
