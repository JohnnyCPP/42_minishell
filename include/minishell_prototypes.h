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
void	ms_handle_sigint(int signal);

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
  * @brief Checks that all tokens in a list are considered valid
  *
  * @param list The token list to be checked
  *
  * @return TRUE if all tokens are valid
  *         FALSE if one or more tokens are not valid
  *
  * It only checks tokens of type word.
  *
  * A token of type word is considered to be valid if:
  *   - In case of containing quotes, they are balanced
  */
int		ms_are_tokens_valid(t_token_list *list);

/**
  * @brief Checks if a character is a whitespace.
  *
  * @param C The character to be checked
  *
  * @return Non-zero value if the character is a whitespace
  *         0 if the character is not a whitespace
  */
int		ms_iswhitespace(const char c);

/**
  * @brief Checks if a character is a redirection.
  *
  * @param C The character to be checked
  *
  * @return Non-zero value if the character is a redirection
  *         0 if the character is not a redirection
  */
int		ms_isredirection(const char c);

/**
  * @brief Checks if a character is a separator.
  *
  * @param C The character to be checked
  *
  * @return Non-zero value if the character is a separator
  *         0 if the character is not a separator
  *
  * A separator includes: whitespaces, redirections, and pipes.
  */
int		ms_isseparator(const char c);

/**
  * @brief Checks if a string equals ">>".
  *
  * @param INPUT The string to be checked
  *
  * @return Non-zero value if the string equals ">>"
  *         0 if the string is not equal to ">>"
  */
int		ms_isappend(const char *input);

/**
  * @brief Checks if a string equals "<<".
  *
  * @param C The string to be checked
  *
  * @return Non-zero value if the string equals "<<"
  *         0 if the string is not equal to "<<"
  */
int		ms_isheredoc(const char *input);

/**
  * @brief Creates a word token read from user input.
  *
  * @param INPUT String read from stdin that contains the tokens to analyze
  * @param list Where the new token will be pushed to
  *
  * @return Length of the analyzed word
  */
int		ms_analyze_word(const char *input, t_token_list *list);

/**
  * @brief Creates a redirection token read from user input.
  *
  * @param INPUT String read from stdin that contains the tokens to analyze
  * @param list Where the new token will be pushed to
  *
  * @return Length of the analyzed redirection
  */
size_t	ms_analyze_redirection(const char *input, t_token_list *list);

/**
  * @brief Creates a pipe token read from user input.
  *
  * @param list Where the new token will be pushed to
  *
  * @return Always 1
  */
int		ms_analyze_pipe(t_token_list *list);

/**
  * @brief If lexemes are quoted, removes them
  *
  * @param list Object whose lexemes will be modified
  * 
  * This function iterates through all tokens, 
  * gets those that are of type word, 
  * and if their lexemes are single or double quoted, 
  * removes them.
  *
  * It also identifies single quoted tokens for variable expansion.
  */
void	ms_strip_quotes(t_token_list *list);

/**
  * @brief Gets the length of a variable expansion tag.
  *
  * @param lexeme Position where the '$' is
  *
  * @return Length of variable expansion tag
  *
  * If the variable expansion contains braces, includes them
  * E.g. ${PATH} returns 7
  */
int		ms_get_var_len(const char *lexeme);

/**
  * @brief Gets the content of an environment variable
  *
  * @param var_name Name of the variable
  *
  * @return Pointer to the variable
  *
  * The returned string is dynamically allocated and must be freed.
  */
char	*ms_get_var_value(char *var_name);

/**
  * @brief Checks if a lexeme is a built-in command
  *
  * @param lexeme The lexeme to be checked
  *
  * @return TRUE if it's a built-in, FALSE otherwise
  */
int		ms_is_builtin(const char *lexeme);

/**
  * @brief Runs a built-in command from a list of tokens
  *
  * @param list The list of tokens from which the command will be run
  *
  * @return The return status of the built-in run, 
  *         or STD_RET_KO if the command does not run
  */
int		ms_run_builtin(t_token_list *list);

/**
  * @brief TODO
  */
int		ms_cd(t_token_list *list);

/**
  * @brief TODO
  */
int		ms_echo(t_token_list *list);

/**
  * @brief TODO
  */
int		ms_env(t_token_list *list);

/**
  * @brief Terminates minishell, it never returns
  *
  * @param list The token list that will be freed
  */
int		ms_exit(t_token_list *list);

/**
  * @brief TODO
  */
int		ms_export(t_token_list *list);

/**
  * @brief TODO
  */
int		ms_pwd(t_token_list *list);

/**
  * @brief TODO
  */
int		ms_unset(t_token_list *list);

#endif
