/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_chdir(const char *path)
{
	if (chdir(path) == FAIL)
	{
		perror(CMD_CD);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static	int	ms_path_not_found(t_shell *shell, const char *path)
{
	t_token	*next;

	if (path)
		return (FALSE);
	next = shell->tokens->head->next;
	if (next && !ft_strcmp(next->lexeme, PREV_PATH))
		ms_puterr(ERR_OLDPWD);
	else
		ms_puterr(ERR_HOME);
	return (TRUE);
}

static	char	*ms_get_path_to_cd(t_shell *shell)
{
	if (!shell->tokens->head->next)
		return (ms_get_var(shell, EVAR_HOME));
	if (!ft_strcmp(shell->tokens->head->next->lexeme, PREV_PATH))
		return (ms_get_var(shell, EVAR_OLDPWD));
	return (shell->tokens->head->next->lexeme);
}

static	int	ms_getcwd(char *buffer, size_t size)
{
	if (!getcwd(buffer, size))
	{
		perror(ERR_GETCWD);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ms_cd(t_shell *shell)
{
	char	*path;
	char	cwd[PATH_MAX];
	char	old_wd[PATH_MAX];

	if (ms_getcwd(old_wd, sizeof(old_wd)) == EXIT_FAILURE)
		return (STD_RET_KO);
	path = ms_get_path_to_cd(shell);
	if (ms_path_not_found(shell, path))
		return (STD_RET_KO);
	if (ms_chdir(path) == EXIT_FAILURE)
		return (STD_RET_KO);
	if (ms_getcwd(cwd, sizeof(cwd)) == EXIT_SUCCESS)
	{
		ms_set_var(shell, EVAR_OLDPWD, old_wd);
		ms_set_var(shell, EVAR_PWD, cwd);
	}
	return (STD_RET_OK);
}
