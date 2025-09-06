/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ms_get_var(t_shell *shell, const char *name)
{
	int	i;
	int	strlen;

	if (!shell->env)
		return (NULL);
	i = 0;
	strlen = (int) ft_strlen(name);
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], name, strlen))
		{
			if (shell->env[i][strlen] == '=')
				return (&shell->env[i][strlen + 1]);
		}
		i ++;
	}
	return (NULL);
}
