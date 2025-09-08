/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_history_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ms_get_history_path(t_shell *shell)
{
	char	*home;
	char	*history_path;

	home = ms_get_var(shell, EVAR_HOME);
	if (!home)
		return (NULL);
	history_path = ms_concat(home, "/", FILE_HISTORY);
	return (history_path);
}
