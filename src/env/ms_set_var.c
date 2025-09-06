/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	char	**ms_envcpy(char **src, int envlen)
{
	char	**envcpy;
	int		i;

	envcpy = (char **) ft_calloc(envlen + 2, sizeof(char *));
	if (!envcpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		envcpy[i] = ft_strdup(src[i]);
		if (!envcpy[i])
		{
			while (i-- > 0)
				free(envcpy[i]);
			free((void *) envcpy);
			return (NULL);
		}
		i ++;
	}
	envcpy[i] = NULL;
	return (envcpy);
}

static	int	ms_exists_env(t_shell *shell, const char *name, char *new_var)
{
	char	**env;
	int		strlen;
	int		i;

	if (!shell->env)
		return (FALSE);
	env = shell->env;
	strlen = (int) ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, strlen))
		{
			if (env[i][strlen] == '=' || env[i][strlen] == '\0')
			{
				free(env[i]);
				shell->env[i] = new_var;
				return (TRUE);
			}
		}
		i ++;
	}
	return (FALSE);
}

static	char	*ms_concat_if_exists(const char *name, const char *value)
{
	if (!name)
		return (NULL);
	if (!value)
		return (ft_strdup(name));
	return (ms_concat(name, "=", value));
}

int	ms_set_var(t_shell *shell, const char *name, const char *value)
{
	int		exists;
	int		envlen;
	char	*concat;
	char	**envcpy;

	concat = ms_concat_if_exists(name, value);
	if (!concat)
		return (EXIT_FAILURE);
	exists = ms_exists_env(shell, name, concat);
	if (exists)
		return (EXIT_SUCCESS);
	envlen = ms_envlen(shell->env);
	envcpy = ms_envcpy(shell->env, envlen);
	if (!envcpy)
	{
		free(concat);
		return (EXIT_FAILURE);
	}
	if (shell->env)
		free((void *) shell->env);
	envcpy[envlen] = concat;
	envcpy[envlen + 1] = NULL;
	shell->env = envcpy;
	return (EXIT_SUCCESS);
}
