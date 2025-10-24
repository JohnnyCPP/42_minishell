/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_configure_signals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	void	ms_handle_noprompt_sigint(int signal)
{
	ms_set_signal(signal);
}

void	ms_set_noprompt_handler(void)
{
	signal(SIGINT, SIG_DFL);
	if (signal(SIGINT, ms_handle_noprompt_sigint) == SIG_ERR)
		perror(ERR_SIGINT);
}

void	ms_handle_sigint(int signal)
{
	char	*newline;

	newline = "\n";
	ms_set_signal(signal);
	write(STDOUT_FILENO, newline, ft_strlen(newline));
	if (rl_on_new_line() == FAIL)
		write(STDERR_FILENO, ERR_ON_NL, ft_strlen(ERR_ON_NL));
	rl_replace_line("", CLEAR_UNDO_LIST);
	rl_redisplay();
}

void	ms_configure_signals(void)
{
	ms_set_signal(SIGNAL_RESET);
	if (signal(SIGINT, ms_handle_sigint) == SIG_ERR)
		perror(ERR_SIGINT);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror(ERR_SIGQUIT);
}
