/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_print_enverr(const char *lexeme)
{
	char	*error;

	error = ms_concat(ERR_ENV, lexeme, "\n");
	ms_puterr(error);
	free(error);
	return (STD_RET_INCORRECT);
}

int	ms_env(t_shell *shell)
{
	t_token_list	*tokens;
	int				i;

	tokens = shell->tokens;
	if (tokens && tokens->head && tokens->head->next)
		return (ms_print_enverr(tokens->head->next->lexeme));
	if (!shell->env)
		return (STD_RET_OK);
	i = 0;
	while (shell->env[i])
	{
		printf("%s\n", shell->env[i]);
		i ++;
	}
	return (STD_RET_OK);
}
