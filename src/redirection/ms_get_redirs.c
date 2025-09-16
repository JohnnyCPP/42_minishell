/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_free_rdrt(t_shell *sh, t_token *prev, t_token **curr, t_token *nxt)
{
	if (prev)
		prev->next = nxt->next;
	else
		sh->tokens->head = nxt->next;
	free((*curr)->lexeme);
	free(*curr);
	free(nxt->lexeme);
	free(nxt);
	if (prev)
		(*curr) = prev->next;
	else
		(*curr) = sh->tokens->head;
}

int	ms_get_redir(t_redir_list **list, t_token *current, t_token **next, int *i)
{
	*next = current->next;
	if (!*next || (*next)->type != T_WORD)
	{
		ms_syntax_error(*next);
		free((*list)->redirs);
		free(*list);
		*list = NULL;
		return (EXIT_FAILURE);
	}
	(*list)->redirs[*i].type = current->type;
	(*list)->redirs[*i].filename = ft_strdup((*next)->lexeme);
	(*list)->redirs[*i].new_fd = NO_FILE_DESCRIPTOR;
	(*list)->redirs[*i].old_fd = NO_FILE_DESCRIPTOR;
	(*i)++;
	return (EXIT_SUCCESS);
}

static	void	ms_populate_redirs(t_shell *shell, t_redir_list **list)
{
	t_token		*previous;
	t_token		*current;
	t_token		*next;
	int			i;

	previous = NULL;
	current = shell->tokens->head;
	next = NULL;
	i = 0;
	while (current)
	{
		if (current->type != T_WORD && current->type != T_PIPE)
		{
			if (ms_get_redir(list, current, &next, &i) == EXIT_FAILURE)
				return ;
			ms_free_rdrt(shell, previous, &current, next);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	shell->tokens->length -= (*list)->length * 2;
}

static	int	ms_get_redirslen(t_token *head)
{
	int	length;

	length = 0;
	while (head)
	{
		if (head->type != T_WORD && head->type != T_PIPE)
			length ++;
		head = head->next;
	}
	return (length);
}

t_redir_list	*ms_get_redirs(t_shell *shell)
{
	t_redir_list	*list;

	list = (t_redir_list *) ft_calloc(1, sizeof(t_redir_list));
	if (!list)
		return (NULL);
	list->length = ms_get_redirslen(shell->tokens->head);
	list->redirs = NULL;
	if (!list->length)
		return (list);
	list->redirs = (t_redir *) ft_calloc(list->length, sizeof(t_redir));
	if (!list->redirs)
	{
		free(list);
		return (NULL);
	}
	ms_populate_redirs(shell, &list);
	ms_recalc_tail(shell);
	return (list);
}
