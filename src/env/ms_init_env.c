/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	char	**ms_copy_env(char **env)
{
	char	**copy;
	int		i;

	i = 0;
	while (env[i])
		i ++;
	copy = (char **) ft_calloc(i + 1, sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (env[i])
	{
		copy[i] = ft_strdup(env[i]);
		if (!copy[i])
		{
			while (i -- > 0)
				free(copy[i]);
			free((void *) copy);
			return (NULL);
		}
		i ++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ms_init_env(t_shell *shell, char **env)
{
	if (env && *env)
		shell->env = ms_copy_env(env);
	else
		shell->env = (char **) ft_calloc(1, sizeof(char *));
}
