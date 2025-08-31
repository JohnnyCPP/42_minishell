/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prototypes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:33:41 by cvicol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_PROTOTYPES_H
# define MINISHELL_PROTOTYPES_H

# include "minishell_structures.h"
# include "libft.h"

void	ms_print_tokens(t_token_list *list);

/**
  * @brief Handler responsible for redisplaying the prompt when pressing Ctrl+C.
  *
  * @param sig Value of SIGINT signal, updates g_signal.
 */
void	ms_handle_sigint(int sig);

/**
  * @brief Sets a handler for SIGINT and ignores SIGQUIT signals.
  */
void	ms_configure_signals(void);

/**
  * @brief Displays the prompt, waits for user input, evaluates it and repeats.
  */
void	ms_read_loop(void);

/**
  * @brief Creates a new token with the data passed through parameters.
  *
  * @param type Category of the new token
  * @param lexeme The token content, a dynamically allocated string
  *
  * @return If success, returns a dynamically allocated token
  *         If memory allocation fails, 
  *         or "lexeme" is not pointing to a valid memory location, 
  *         returns NULL
  */
t_token	*ms_create_token(t_token_type type, char *lexeme);

/**
  * @brief Adds a token to a list of tokens.
  *
  * @param list The list in which the token will be pushed to
  * @param new The token that will be added
  */
void	ms_push_token(t_token_list *list, t_token *new);

/**
  * @brief Frees dynamic memory of all tokens in a list.
  *
  * @param list The list whose tokens will be freed
  */
void	ms_free_tokens(t_token_list *list);

/**
  * @brief Frees dynamic memory of a list of tokens.
  *
  * @param list Double pointer to the list to be freed
  *
  * This function also frees all the tokens in the list, 
  * and assigns the memory location of the list to NULL
  */
void	ms_delete_list(t_token_list **list);

/**
  * @brief Checks if a character is a whitespace.
  *
  * @param C The character to be checked
  */
int		ms_iswhitespace(const char c);

/**
  * @brief Checks if a character is a redirection.
  *
  * @param C The character to be checked
  */
int		ms_isredirection(const char c);

/**
  * @brief Checks if a character is a separator.
  *
  * @param C The character to be checked
  *
  * A separator includes: whitespaces, redirections, and pipes.
  */
int		ms_isseparator(const char c);

/**
  * @brief Checks if a string equals ">>".
  *
  * @param INPUT The string to be checked
  */
int		ms_isappend(const char *input);

/**
  * @brief Checks if a string equals "<<".
  *
  * @param C The string to be checked
  */
int		ms_isheredoc(const char *input);

/**
  * @brief Creates a word token read from user input.
  *
  * @param INPUT String read from stdin that contains the tokens to analyze
  * @param list Where the new token will be pushed to
  */
int		ms_analyze_word(const char *input, t_token_list *list);

/**
  * @brief Creates a redirection token read from user input.
  *
  * @param INPUT String read from stdin that contains the tokens to analyze
  * @param list Where the new token will be pushed to
  */
size_t	ms_analyze_redirection(const char *input, t_token_list *list);

/**
  * @brief Creates a pipe token read from user input.
  *
  * @param list Where the new token will be pushed to
  */
int		ms_analyze_pipe(t_token_list *list);

#endif
