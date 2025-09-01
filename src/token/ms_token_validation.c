/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_has_unclosed_quotes(const char *lexeme)
{
	int	in_singleq;
	int	in_doubleq;

	in_singleq = FALSE;
	in_doubleq = FALSE;
	while (*lexeme)
	{
		if (!in_doubleq && *lexeme == '\'')
			in_singleq = !in_singleq;
		else if (!in_singleq && *lexeme == '\"')
			in_doubleq = !in_doubleq;
		lexeme ++;
	}
	return (in_singleq || in_doubleq);
}

static	int	ms_is_valid(const char *lexeme)
{
	if (ms_has_unclosed_quotes(lexeme))
	{
		printf(MSG_UNCL_QUOT, lexeme);
		return (FALSE);
	}
	return (TRUE);
}

int	ms_are_tokens_valid(t_token_list *list)
{
	t_token	*current;

	current = list->head;
	while (current)
	{
		if (current->type == T_WORD && current->lexeme)
		{
			if (!ms_is_valid(current->lexeme))
				return (FALSE);
		}
		current = current->next;
	}
	return (TRUE);
}
