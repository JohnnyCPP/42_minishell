/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_token_list	*ms_create_token_list(void)
{
	t_token_list	*list;

	list = ft_calloc(1, sizeof(t_token_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return (list);
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

void	ms_push_token(t_token_list *list, t_token *new)
{
	if (!list || !new)
		return ;
	if (!list->tail)
	{
		list->head = new;
		list->tail = new;
	}
	else
	{
		list->tail->next = new;
		list->tail = new;
	}
	list->length ++;
}

void	ms_free_tokens(t_token_list *list)
{
	t_token	*current;
	t_token	*next;

	if (!list)
		return ;
	current = list->head;
	while (current)
	{
		next = current->next;
		if (current->lexeme)
			free(current->lexeme);
		free(current);
		current = next;
	}
}

void	ms_delete_list(t_token_list **list)
{
	if (!list)
		return ;
	ms_free_tokens(*list);
	free(*list);
	*list = NULL;
}
