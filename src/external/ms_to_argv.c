/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_to_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	**ms_to_argv(t_token_list *tokens)
{
	t_token	*current;
	char	**argv;
	int		i;

	if (!tokens || !tokens->length)
		return (NULL);
	argv = (char **) ft_calloc(tokens->length + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	current = tokens->head;
	i = 0;
	while (current)
	{
		argv[i] = ft_strdup(current->lexeme);
		if (!argv[i])
		{
			ms_free_strings(argv);
			return (NULL);
		}
		current = current->next;
		i ++;
	}
	argv[i] = NULL;
	return (argv);
}
