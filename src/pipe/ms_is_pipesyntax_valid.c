/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_pipesyntax_valid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_correct_pipesyntax(t_token *current)
{
	if (current->type == T_PIPE)
	{
		if (!current->next)
		{
			ms_syntax_error(current);
			return (FALSE);
		}
		if (current->next->type == T_PIPE)
		{
			ms_syntax_error(current);
			return (FALSE);
		}
	}
	return (TRUE);
}

int	ms_is_pipesyntax_valid(t_shell *shell)
{
	t_token	*current;

	current = shell->tokens->head;
	if (current->type == T_PIPE)
	{
		ms_syntax_error(current);
		return (FALSE);
	}
	while (current)
	{
		if (!ms_correct_pipesyntax(current))
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
