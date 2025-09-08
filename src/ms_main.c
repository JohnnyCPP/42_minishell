/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	ms_init_env(&shell, env);
	ms_configure_signals();
	ms_load_history(&shell);
	ms_read_loop(&shell);
	ms_free_resources(&shell);
	return (EXIT_SUCCESS);
}
