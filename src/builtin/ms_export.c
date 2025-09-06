/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_print_all(t_shell *shell)
{
	char	*eq_sign;
	char	*name;
	char	*value;
	int		i;

	if (!shell->env)
		return (STD_RET_OK);
	i = 0;
	while (shell->env[i])
	{
		eq_sign = ft_strchr(shell->env[i], '=');
		if (eq_sign)
		{
			name = ft_substr(shell->env[i], 0, eq_sign - shell->env[i]);
			value = eq_sign + 1;
			printf(EXPORT_FMT, name, value);
			free(name);
		}
		else
			printf(EXPORT_FMT_NOVAL, shell->env[i]);
		i ++;
	}
	return (STD_RET_OK);
}

static	int	ms_print_exporterr(const char *arg, char *name)
{
	char	*error;

	error = ms_concat(ERR_EXPORT_HEAD, arg, ERR_EXPORT_TAIL);
	ms_puterr(error);
	free(error);
	free(name);
	return (EXIT_FAILURE);
}

static	int	ms_process_arg(t_shell *shell, const char *arg)
{
	char	*eq_sign;
	char	*name;
	char	*value;
	int		result;

	eq_sign = ft_strchr(arg, '=');
	if (eq_sign)
	{
		name = ft_substr(arg, 0, eq_sign - arg);
		value = eq_sign + 1;
	}
	else
	{
		name = ft_strdup(arg);
		value = NULL;
	}
	if (!ms_is_validenv(name))
		return (ms_print_exporterr(arg, name));
	result = ms_set_var(shell, name, value);
	free(name);
	return (result);
}

int	ms_export(t_shell *shell)
{
	t_token	*current;
	int		exit_code;

	if (!shell->tokens->head->next)
		return (ms_print_all(shell));
	current = shell->tokens->head->next;
	exit_code = STD_RET_OK;
	while (current)
	{
		if (ms_process_arg(shell, current->lexeme) == EXIT_FAILURE)
			exit_code = STD_RET_KO;
		current = current->next;
	}
	return (exit_code);
}
