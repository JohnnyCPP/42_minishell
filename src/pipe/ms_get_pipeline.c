/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_error_allocating(t_shell *shell)
{
	int	i;

	if (!shell || !shell->pipeline)
		return (EXIT_FAILURE);
	i = 0;
	while (i < shell->pipeline->length)
	{
		if (shell->pipeline->commands[i])
			ms_delete_tokens(&shell->pipeline->commands[i]);
		i ++;
	}
	if (shell->pipeline->commands)
		free(shell->pipeline->commands);
	if (shell->pipeline)
		free(shell->pipeline);
	shell->pipeline = NULL;
	return (EXIT_FAILURE);
}

static	int	ms_add_to_list(t_shell *sh, t_token_list **li, t_token **to, int *i)
{
	if ((*to)->type == T_PIPE)
	{
		sh->pipeline->commands[*i] = *li;
		sh->pipeline->length ++;
		*li = ms_create_token_list();
		if (!*li)
			return (ms_error_allocating(sh));
		(*i)++;
	}
	else
		ms_append_token(*li, (*to)->type, ft_strdup((*to)->lexeme));
	*to = (*to)->next;
	return (EXIT_SUCCESS);
}

static	int	ms_allocate_pipeline(t_shell *shell, t_token_list **list)
{
	int	length;

	shell->pipeline = (t_pipeline *) ft_calloc(1, sizeof(t_pipeline));
	if (!shell->pipeline)
		return (EXIT_FAILURE);
	shell->pipeline->length = 0;
	length = ms_count_pipes(shell->tokens) + 1;
	shell->pipeline->commands = ft_calloc(length, sizeof(t_token_list *));
	if (!shell->pipeline->commands)
	{
		free(shell->pipeline);
		return (EXIT_FAILURE);
	}
	*list = ms_create_token_list();
	if (!*list)
	{
		free(shell->pipeline->commands);
		free(shell->pipeline);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ms_get_pipeline(t_shell *shell)
{
	t_token_list	*list;
	t_token			*current;
	int				i;
	int				return_code;

	list = NULL;
	if (ms_allocate_pipeline(shell, &list) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	current = shell->tokens->head;
	i = 0;
	while (current)
	{
		return_code = ms_add_to_list(shell, &list, &current, &i);
		if (return_code == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	if (list)
	{
		shell->pipeline->commands[i] = list;
		shell->pipeline->length ++;
	}
	return (EXIT_SUCCESS);
}
