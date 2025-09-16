/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redir_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_syntax_error(const t_token *token)
{
	char	*error;
	char	*lexeme;

	if (!token || !token->lexeme)
		lexeme = DEFAULT_LEXEME;
	else
		lexeme = token->lexeme;
	error = ms_concat(ERR_SYNTAX_HEAD, lexeme, ERR_SYNTAX_TAIL);
	ms_puterr(error);
	free(error);
}
