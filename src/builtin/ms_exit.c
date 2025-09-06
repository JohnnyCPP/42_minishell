/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_exit(t_shell *shell)
{
	printf(MSG_EXIT_SHELL);
	if (!shell->tokens || !shell->tokens->head)
		exit(STD_RET_OK);
	rl_clear_history();
	ms_delete_tokens(&shell->tokens);
	exit(STD_RET_OK);
	return (STD_RET_OK);
}
