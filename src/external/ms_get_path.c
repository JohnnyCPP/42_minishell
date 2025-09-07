/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	void	ms_permission_denied(const char *cmd)
{
	char	*error;

	error = ms_concat(ERR_EXECVE_HEAD, cmd, ERR_PERM_DENIED);
	ms_puterr(error);
	free(error);
}

static	void	ms_is_a_directory(const char *cmd)
{
	char	*error;

	error = ms_concat(ERR_EXECVE_HEAD, cmd, ERR_IS_DIRECTORY);
	ms_puterr(error);
	free(error);
}

static	char	*ms_free_return(char **paths, char *full_path, const char *cmd)
{
	struct stat	stats;
	int			not_executable;
	int			is_directory;

	not_executable = access(full_path, X_OK);
	is_directory = !stat(full_path, &stats) && S_ISDIR(stats.st_mode);
	ms_free_strings(paths);
	if (!not_executable)
		return (full_path);
	free(full_path);
	if (is_directory)
		ms_is_a_directory(cmd);
	else
		ms_permission_denied(cmd);
	return (NULL);
}

char	*ms_get_path(t_shell *shell, const char *cmd)
{
	char	*env_path;
	char	*full_path;
	char	**paths;
	int		i;

	if (ms_is_path(cmd))
		return (ft_strdup(cmd));
	env_path = ms_get_var(shell, EVAR_PATH);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ms_concat(paths[i ++], "/", cmd);
		if (!full_path)
			continue ;
		if (!access(full_path, F_OK))
			return (ms_free_return(paths, full_path, cmd));
		free(full_path);
	}
	ms_free_strings(paths);
	return (NULL);
}
