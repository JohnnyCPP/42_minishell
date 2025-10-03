/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_heredoc_handler.c                           :+:      :+:    :+:   */
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

void	ms_set_heredoc_handler(void)
{
	struct sigaction	new_sigint;

	new_sigint.sa_handler = ms_handle_heredoc_sigint;
	sigemptyset(&new_sigint.sa_mask);
	new_sigint.sa_flags = 0;
	sigaction(SIGINT, &new_sigint, NULL);
	ms_set_signal(SIGNAL_RESET);
	rl_event_hook = ms_heredoc_event_hook;
}
