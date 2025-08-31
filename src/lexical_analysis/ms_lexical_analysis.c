/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexical_analysis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_get_wordlen(const char *word)
{
	int	wordlen;
	int	in_singleq;
	int	in_doubleq;

	wordlen = 0;
	in_singleq = 0;
	in_doubleq = 0;
	while (word[wordlen])
	{
		if (!in_doubleq && word[wordlen] == '\'')
			in_singleq = !in_singleq;
		else if (!in_singleq && word[wordlen] == '\"')
			in_doubleq = !in_doubleq;
		else if (!in_singleq && !in_doubleq && ms_isseparator(word[wordlen]))
			break ;
		wordlen ++;
	}
	return (wordlen);
}

int	ms_analyze_word(const char *input, t_token_list *list)
{
	t_token	*word;
	int		wordlen;
	char	*lexeme;

	wordlen = ms_get_wordlen(input);
	lexeme = ft_substr(input, 0, wordlen);
	word = ms_create_token(T_WORD, lexeme);
	ms_push_token(list, word);
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

size_t	ms_analyze_redirection(const char *input, t_token_list *list)
{
	if (ms_isappend(input))
		return (ms_push_redir(list, T_REDIR_APND, APPND_STR));
	else if (ms_isheredoc(input))
		return (ms_push_redir(list, T_HEREDOC, HEREDOC_STR));
	else if (*input == '>')
		return (ms_push_redir(list, T_REDIR_OUT, REDIROUT_STR));
	else if (*input == '<')
		return (ms_push_redir(list, T_REDIR_IN, REDIRIN_STR));
	return (0);
}

int	ms_analyze_pipe(t_token_list *list)
{
	t_token		*pipe;

	pipe = ms_create_token(T_PIPE, ft_strdup("|"));
	ms_push_token(list, pipe);
	return (1);
}
