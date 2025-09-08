/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_read_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_read_loop(t_shell *shell)
{
	while (TRUE)
	{
		ms_set_signal(SIGNAL_RESET);
		shell->input = readline(PROMPT);
		if (!shell->input)
			break ;
		if (shell->input[0] != '\0')
		{
			ms_evaluate(shell);
			continue ;
		}
		if (ms_get_signal() == SIGINT)
		{
			free(shell->input);
			continue ;
		}
		free(shell->input);
	}
}
