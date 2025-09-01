/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_var_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

char	*ms_get_var_value(char *var_name)
{
	char	*name;
	char	*value;
	// TODO
	int		exit_status = 0;

	if (!ft_strncmp(var_name, "$?", 2))
		return (ft_itoa(exit_status));
	if (var_name[0] == '$' && var_name[1] == '{')
	{
		name = ft_substr(var_name, 2, ft_strlen(var_name) - 3);
		value = getenv(name);
		free(name);
		if (value)
			return (ft_strdup(value));
		return (ft_strdup(""));
	}
	if (var_name[0] == '$')
	{
		value = getenv(var_name + 1);
		if (value)
			return (ft_strdup(value));
		return (ft_strdup(""));
	}
	return (ft_strdup(""));
}
