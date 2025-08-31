/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_handle_sigint(int sig)
{
	char	*newline;

	newline = "\n";
	g_signal = sig;
	write(STDOUT_FILENO, newline, ft_strlen(newline));
	if (rl_on_new_line() == FAIL)
		write(STDOUT_FILENO, ERR_ON_NL, ft_strlen(ERR_ON_NL));
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ms_configure_signals(void)
{
	struct sigaction	sa_sigint;

	g_signal = 0;
	sa_sigint.sa_handler = ms_handle_sigint;
	sigemptyset(&sa_sigint.sa_mask);
	sa_sigint.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa_sigint, NULL) == FAIL)
		perror(ERR_SIGINT);
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror(ERR_SIGQUIT);
}
