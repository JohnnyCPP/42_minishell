/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_is_builtin(const char *lexeme)
{
	if (!ft_strcmp(cmd, CMD_CD))
		return (TRUE);
	if (!ft_strcmp(cmd, CMD_ECHO))
		return (TRUE);
	if (!ft_strcmp(cmd, CMD_ENV))
		return (TRUE);
	if (!ft_strcmp(cmd, CMD_EXIT))
		return (TRUE);
	if (!ft_strcmp(cmd, CMD_EXPORT))
		return (TRUE);
	if (!ft_strcmp(cmd, CMD_PWD))
		return (TRUE);
	if (!ft_strcmp(cmd, CMD_UNSET))
		return (TRUE);
	return (FALSE);
}
