/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_token_list	*ms_create_token_list(void)
{
	t_token_list	*tokens;

	tokens = ft_calloc(1, sizeof(t_token_list));
	if (!tokens)
		return (NULL);
	tokens->head = NULL;
	tokens->tail = NULL;
	tokens->length = 0;
	return (tokens);
}

t_token	*ms_create_token(t_token_type type, char *lexeme)
{
	t_token	*token;

	if (!lexeme)
		return (NULL);
	token = (t_token *) ft_calloc(1, sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->is_singleq = FALSE;
	token->lexeme = lexeme;
	token->next = NULL;
	return (token);
}

void	ms_push_token(t_token_list *tokens, t_token *new)
{
	if (!tokens || !new)
		return ;
	if (!tokens->tail)
	{
		tokens->head = new;
		tokens->tail = new;
	}
	else
	{
		tokens->tail->next = new;
		tokens->tail = new;
	}
	tokens->length ++;
}

void	ms_free_tokens(t_token_list *tokens)
{
	t_token	*current;
	t_token	*next;

	if (!tokens)
		return ;
	current = tokens->head;
	while (current)
	{
		next = current->next;
		if (current->lexeme)
			free(current->lexeme);
		free(current);
		current = next;
	}
}

void	ms_delete_tokens(t_token_list **tokens)
{
	if (!tokens || !*tokens)
		return ;
	ms_free_tokens(*tokens);
	free(*tokens);
	*tokens = NULL;
}
