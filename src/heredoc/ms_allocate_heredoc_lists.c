/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_allocate_heredoc_lists.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_allocate_heredoc_lists(t_shell *shell)
{
	int	len;

	len = shell->pipeline->length;
	shell->pipeline->hdoc_lists = ft_calloc(len, sizeof(t_heredoc_list));
	if (!shell->pipeline->hdoc_lists)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
