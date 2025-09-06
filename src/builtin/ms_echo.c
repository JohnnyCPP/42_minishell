/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	void	ms_echo_tokens(t_token *current, int skip_newline)
{
	if (current && skip_newline)
		current = current->next;
	while (current)
	{
		printf("%s", current->lexeme);
		current = current->next;
		if (current)
			printf(" ");
	}
}

static	int	ms_is_nlflag(const char *lexeme)
{
	if (!ft_strcmp(lexeme, "-n"))
		return (TRUE);
	return (FALSE);
}

int	ms_echo(t_shell *shell)
{
	t_token	*current;
	int		skip_newline;

	if (!shell->tokens || !shell->tokens->head)
		return (STD_RET_OK);
	current = shell->tokens->head->next;
	if (!current)
	{
		printf("\n");
		return (STD_RET_OK);
	}
	skip_newline = ms_is_nlflag(current->lexeme);
	ms_echo_tokens(current, skip_newline);
	if (!skip_newline)
		printf("\n");
	return (STD_RET_OK);
}
