/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	void	ms_numarg_required_error(const char *arg)
{
	char	*error;

	write(STDOUT_FILENO, MSG_EXIT_SHELL, ft_strlen(MSG_EXIT_SHELL));
	error = ms_concat(ERR_EXIT_NUMARG_HEAD, arg, ERR_EXIT_NUMARG_TAIL);
	ms_puterr(error);
	free(error);
}

static	int	ms_is_number(const char *arg)
{
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (FALSE);
		arg ++;
	}
	return (TRUE);
}

int	ms_exit(t_shell *shell)
{
	unsigned int	exit_status;
	char			*arg;

	if (shell->tokens->length > EXIT_TOKEN_LIMIT)
	{
		ms_puterr(ERR_EXIT_ARGS);
		return (STD_RET_INCORRECT);
	}
	exit_status = STD_RET_OK;
	if (shell->tokens->length > 1)
	{
		arg = shell->tokens->head->next->lexeme;
		if (!ms_is_number(arg))
		{
			ms_numarg_required_error(arg);
			return (STD_RET_INCORRECT);
		}
		else if (ft_ioverflow(arg))
			exit_status = STD_RET_INCORRECT;
		else
			exit_status = (unsigned int) ft_atoi(arg);
	}
	ms_free_resources(shell);
	exit(exit_status);
	return (exit_status);
}
