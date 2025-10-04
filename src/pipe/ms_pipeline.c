/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_pipeline(t_shell *shell)
{
	if (ms_is_pipesyntax_valid(shell) == FALSE)
		return ;
	if (ms_get_pipeline(shell) == EXIT_FAILURE)
		return ;
	if (ms_get_heredocs(shell) == EXIT_FAILURE)
		return ;
	shell->exit_code = ms_run_pipeline(shell, shell->pipeline);
	ms_free_heredoc_lists(shell);
	ms_free_pipeline(&shell->pipeline);
}
