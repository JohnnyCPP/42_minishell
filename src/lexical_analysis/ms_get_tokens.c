/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:02:01 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:39:30 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

t_token_list	*ms_get_tokens(const char *input)
{
	t_token_list	*tokens;
	int				i;

	tokens = ms_create_token_list();
	if (!tokens || !input)
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (ms_iswhitespace(input[i]))
			i ++;
		else if (input[i] == '|')
			i += ms_analyze_pipe(tokens);
		else if (ms_isredirection(input[i]))
			i += (int) ms_analyze_redirection(&input[i], tokens);
		else
			i += ms_analyze_word(&input[i], tokens);
	}
	return (tokens);
}
