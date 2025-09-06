/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset_var.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	char	**ms_free_return(char **unset, int j)
{
	while (j -- > 0)
		free(unset[j]);
	free((void *) unset);
	return (NULL);
}

static	char	**ms_remove(char **env, int index, int envlen)
{
	char	**remove;
	int		i;
	int		j;

	remove = (char **) ft_calloc(envlen, sizeof(char *));
	if (!remove)
		return (NULL);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (i != index)
		{
			remove[j] = ft_strdup(env[i]);
			if (!remove[j])
				return (ms_free_return(remove, j));
			j ++;
		}
		i ++;
	}
	remove[j] = NULL;
	return (remove);
}

static	int	ms_get_index(t_shell *shell, const char *name)
{
	int	strlen;
	int	i;

	if (!shell->env)
		return (FAIL);
	strlen = (int) ft_strlen(name);
	i = 0;
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], name, strlen))
		{
			if (shell->env[i][strlen] == '=' || shell->env[i][strlen] == '\0')
				return (i);
		}
		i ++;
	}
	return (FAIL);
}

int	ms_unset_var(t_shell *shell, const char *name)
{
	int		index;
	int		envlen;
	char	**remove;

	index = ms_get_index(shell, name);
	if (index == FAIL)
		return (EXIT_SUCCESS);
	envlen = ms_envlen(shell->env);
	remove = ms_remove(shell->env, index, envlen);
	if (!remove)
		return (EXIT_FAILURE);
	free(shell->env[index]);
	free((void *) shell->env);
	shell->env = remove;
	return (EXIT_SUCCESS);
}
