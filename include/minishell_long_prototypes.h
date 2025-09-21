/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_long_prototypes.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:33:41 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_LONG_PROTOTYPES_H
# define MINISHELL_LONG_PROTOTYPES_H

/**
  * @brief Gets the current signal value.
  *
  * @return The current value of the signal received.
  */
sig_atomic_t	ms_get_signal(void);

/**
  * @brief Updates the signal value.
  *
  * @param signal The new value to be set.
  */
void			ms_set_signal(sig_atomic_t signal);

/**
  * @brief Initializes an empty list of tokens.
  *
  * @return If success, returns a dynamically allocated list of tokens
  *         If memory allocation fails, returns NULL
  */
t_token_list	*ms_create_token_list(void);

/**
  * @brief Splits the input string into tokens, respecting special characters.
  *
  * @param input Source string from which tokens will be created
  *
  * @return If success, returns a dynamically allocated list of tokens
  *         If "input" does not contain a valid memory location,
  *         or if memory allocation fails,
  *         returns NULL
  *
  * A Lexeme is the smallest meaningful unit of text in a language.
  * It's a raw sequence of characters found in the source code, 
  * which is then categorized.
  *
  * This function is a Lexer (short for Lexical Analyzer), the piece 
  * of code that takes the raw input string and breaks it down into a 
  * sequence of Lexemes.
  *
  * But it doesn't just output the raw strings, it also tags each 
  * Lexeme with a Token Type.
  * This process is called Lexical Analysis or Tokenization.
  *
  * This function returns a list of Tokens.
  * A Token is defined as a categorized Lexeme.
  */
t_token_list	*ms_get_tokens(const char *input);

/**
  * @brief Gets a list of redirections from a list of tokens.
  *
  * @param shell The shell environment where the list of tokens is.
  * 
  * @return If success, returns the list of redirections.
  *         If memory allocation fails, returns NULL.
  *         If syntax error occurs, returns NULL.
  * 
  * Allocates memory for a list of redirections, iterates through 
  * the list of tokens, initializes each redirection with its type 
  * and value, and frees the tokens from the token list that are 
  * identified as redirections.
  * 
  * If a syntax error occurs, prints an error message.
  * 
  * At the end, recalculates the tail of the list of tokens.
  */
t_redir_list	*ms_get_redirs(t_shell *shell);

#endif
