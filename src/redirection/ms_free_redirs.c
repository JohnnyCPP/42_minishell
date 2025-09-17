/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_redirs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_free_redirs(t_redir_list **list)
{
	int	i;

	if (!list || !*list)
		return (STD_RET_KO);
	ms_revert_redirs(*list);
	i = 0;
	while (i < (*list)->length)
	{
		if ((*list)->redirs[i].filename)
			free((*list)->redirs[i].filename);
		i ++;
	}
	free((*list)->redirs);
	free(*list);
	*list = NULL;
	return (STD_RET_KO);
}
