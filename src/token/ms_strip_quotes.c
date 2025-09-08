/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strip_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_append(char **result, const char current)
{
	char	aux[2];
	char	*strjoin;

	aux[0] = current;
	aux[1] = '\0';
	strjoin = ft_strjoin(*result, aux);
	free(*result);
	*result = strjoin;
	return (1);
}

static	int	ms_expand(char **result, const char *lexeme, t_shell *shell)
{
	int		var_len;
	char	*var_name;
	char	*var_value;
	char	*strjoin;

	var_len = ms_get_var_len(lexeme);
	if (!var_len)
		return (ms_append(result, '$'));
	var_name = ft_substr(lexeme, 0, var_len);
	var_value = ms_get_var_value(var_name, shell);
	free(var_name);
	strjoin = ft_strjoin(*result, var_value);
	free(*result);
	free(var_value);
	*result = strjoin;
	return (var_len);
}

static	int	ms_expand_or_append(int sq, char **res, const char *lx, t_shell *sh)
{
	if (!sq && lx[0] == '$')
		return (ms_expand(res, lx, sh));
	return (ms_append(res, lx[0]));
}

static	char	*ms_process_sequentially(const char *lexeme, t_shell *shell)
{
	char	*result;
	int		in_singleq;
	int		in_doubleq;
	int		i;

	result = ft_strdup("");
	in_singleq = FALSE;
	in_doubleq = FALSE;
	i = 0;
	while (lexeme[i])
	{
		if (!in_singleq && lexeme[i] == '\"')
		{
			in_doubleq = !in_doubleq;
			i ++;
		}
		else if (!in_doubleq && lexeme[i] == '\'')
		{
			in_singleq = !in_singleq;
			i ++;
		}
		else
			i += ms_expand_or_append(in_singleq, &result, &lexeme[i], shell);
	}
	return (result);
}

void	ms_strip_quotes(t_shell *shell)
{
	t_token	*current;
	char	*new_lexeme;

	current = shell->tokens->head;
	while (current)
	{
		if (current->type == T_WORD && current->lexeme)
		{
			new_lexeme = ms_process_sequentially(current->lexeme, shell);
			free(current->lexeme);
			current->lexeme = new_lexeme;
		}
		current = current->next;
	}
}
