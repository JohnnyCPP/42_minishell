/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

/**
  * NOTE: this FILE is used for debugging, 
  *       and it will be removed in the stable release
  */

static	const	char	*ms_get_name(int token)
{
	if (token == T_WORD)
		return ("WORD");
	else if (token == T_PIPE)
		return ("PIPE");
	else if (token == T_REDIR_IN)
		return ("REDIR_IN");
	else if (token == T_REDIR_OUT)
		return ("REDIR_OUT");
	else if (token == T_REDIR_APND)
		return ("REDIR_APPEND");
	else if (token == T_HEREDOC)
		return ("HEREDOC");
	return ("UNKNOWN");
}

void	ms_print_tokens(t_token_list *list)
{
	t_token	*current;
	int		i;

	current = list->head;
	i = 0;
	printf("DEBUG: printing %d lexemes\n", list->length);
	while (current)
	{
		i ++;
		printf("\t#%d %s", i, ms_get_name(current->type));
		if (current->lexeme)
			printf("\t\"%s\"", current->lexeme);
		printf("\n");
		current = current->next;
	}
	printf("DEBUG: end of printing\n");
}
