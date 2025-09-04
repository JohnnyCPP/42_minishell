/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_is_builtin(const char *lexeme)
{
	if (!lexeme)
		return (FALSE);
	if (!ft_strcmp(lexeme, CMD_CD))
		return (TRUE);
	if (!ft_strcmp(lexeme, CMD_ECHO))
		return (TRUE);
	if (!ft_strcmp(lexeme, CMD_ENV))
		return (TRUE);
	if (!ft_strcmp(lexeme, CMD_EXIT))
		return (TRUE);
	if (!ft_strcmp(lexeme, CMD_EXPORT))
		return (TRUE);
	if (!ft_strcmp(lexeme, CMD_PWD))
		return (TRUE);
	if (!ft_strcmp(lexeme, CMD_UNSET))
		return (TRUE);
	return (FALSE);
}
