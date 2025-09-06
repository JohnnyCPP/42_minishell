/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexical_analysis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_get_wordlen(const char *word)
{
	int	in_singleq;
	int	in_doubleq;
	int	i;

	in_singleq = FALSE;
	in_doubleq = FALSE;
	i = 0;
	while (word[i])
	{
		if (!in_doubleq && word[i] == '\'')
			in_singleq = !in_singleq;
		else if (!in_singleq && word[i] == '\"')
			in_doubleq = !in_doubleq;
		else if (!in_singleq && !in_doubleq && ms_isseparator(word[i]))
			break ;
		i ++;
	}
	return (i);
}

int	ms_analyze_word(const char *input, t_token_list *tokens)
{
	t_token	*word;
	int		wordlen;
	char	*lexeme;

	wordlen = ms_get_wordlen(input);
	lexeme = ft_substr(input, 0, wordlen);
	word = ms_create_token(T_WORD, lexeme);
	ms_push_token(tokens, word);
	return (wordlen);
}

static	size_t	ms_push_redir(t_token_list *l, t_token_type t, const char *lex)
{
	t_token	*redir;
	size_t	strlen;

	redir = ms_create_token(t, ft_strdup(lex));
	ms_push_token(l, redir);
	strlen = ft_strlen(lex);
	return (strlen);
}

size_t	ms_analyze_redirection(const char *input, t_token_list *tokens)
{
	if (ms_isappend(input))
		return (ms_push_redir(tokens, T_REDIR_APND, APPND_STR));
	else if (ms_isheredoc(input))
		return (ms_push_redir(tokens, T_HEREDOC, HEREDOC_STR));
	else if (*input == '>')
		return (ms_push_redir(tokens, T_REDIR_OUT, REDIROUT_STR));
	else
		return (ms_push_redir(tokens, T_REDIR_IN, REDIRIN_STR));
}

int	ms_analyze_pipe(t_token_list *tokens)
{
	t_token		*pipe;

	pipe = ms_create_token(T_PIPE, ft_strdup("|"));
	ms_push_token(tokens, pipe);
	return (1);
}
