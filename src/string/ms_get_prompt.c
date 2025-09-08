/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:16:55 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ms_get_prompt(void)
{
	char	cwd[PATH_MAX];
	char	*strjoin;

	if (getcwd(cwd, sizeof(cwd)))
	{
		strjoin = ft_strjoin(cwd, PROMPT_TAIL);
		return (strjoin);
	}
	return (ft_strdup(FALLBACK_PROMPT));
}
