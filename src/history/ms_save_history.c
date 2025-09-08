/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_save_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_save_history(t_shell *shell)
{
	HIST_ENTRY	**history;
	char		*history_path;
	int			fd;
	int			i;

	// history_list() function is illegal
	history = history_list();
	if (!history)
		return ;
	history_path = ms_get_history_path(shell);
	if (!history_path)
		return ;
	fd = open(history_path, O_WRONLY | O_CREAT | O_TRUNC, MODE_RW);
	if (fd == FAIL)
	{
		free(history_path);
		return ;
	}
	i = 0;
	while (history[i])
	{
		ft_putstr_fd(history[i]->line, fd);
		ft_putstr_fd("\n", fd);
		i ++;
	}
	close(fd);
	free(history_path);
}
