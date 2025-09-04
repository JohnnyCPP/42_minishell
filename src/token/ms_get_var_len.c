/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_var_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

int	ms_get_var_len(const char *lexeme)
{
	int	len;

	len = 0;
	if (lexeme[0] == '$')
	{
		len ++;
		if (lexeme[1] == '?')
			return (2);
		if (lexeme[1] == '{')
		{
			len ++;
			while (lexeme[len] && lexeme[len] != '}')
				len ++;
			if (lexeme[len] == '}')
				len ++;
			return (len);
		}
		while (lexeme[len] && (ft_isalnum(lexeme[len]) || lexeme[len] == '_'))
			len ++;
	}
	return (len);
}
