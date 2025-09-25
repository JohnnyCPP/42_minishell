/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_redirtoken.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:02:01 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:39:30 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_is_redirtoken(t_token *token)
{
	if (!ft_strcmp(token->lexeme, REDIROUT_STR))
		return (TRUE);
	if (!ft_strcmp(token->lexeme, REDIRIN_STR))
		return (TRUE);
	if (!ft_strcmp(token->lexeme, APPND_STR))
		return (TRUE);
	if (!ft_strcmp(token->lexeme, HEREDOC_STR))
		return (TRUE);
	return (FALSE);
}
