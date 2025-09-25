/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_epilogue.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_redir_epilogue(t_shell *shell, t_redir_list **list, int is_child)
{
	*list = ms_get_redirs(shell);
	if (!list)
	{
		if (is_child)
			ms_free_childres(shell);
		return (EXIT_FAILURE);
	}
	if (ms_apply_redirs(*list) == EXIT_FAILURE)
	{
		if (is_child)
			ms_free_childres(shell);
		ms_free_redirs(list);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
