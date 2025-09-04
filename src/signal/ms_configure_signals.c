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

void	ms_handle_sigint(int signal)
{
	char	*newline;

	newline = "\n";
	ms_set_signal(signal);
	write(STDOUT_FILENO, newline, ft_strlen(newline));
	if (rl_on_new_line() == FAIL)
		write(STDOUT_FILENO, ERR_ON_NL, ft_strlen(ERR_ON_NL));
	rl_replace_line("", CLEAR_UNDO_LIST);
	rl_redisplay();
}

void	ms_configure_signals(void)
{
	struct sigaction	sa_sigint;

	ms_set_signal(SIGNAL_RESET);
	sa_sigint.sa_handler = ms_handle_sigint;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa_sigint, NULL) == FAIL)
		perror(ERR_SIGINT);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror(ERR_SIGQUIT);
}
