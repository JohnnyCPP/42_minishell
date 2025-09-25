/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prototypes.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:33:41 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_PROTOTYPES_H
# define MINISHELL_PROTOTYPES_H

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
  * @brief Prints an error message to the stderr.
  *
  * @param err The error message to be printed.
  */
void	ms_puterr(const char *err);

/**
  * @brief Joins three strings together in a specific order.
  *
  * @param str1 The leftmost string.
  * @param str2 The string in the middle.
  * @param str3 The rightmost string.
  *
  * @return A dynamically allocated string containing the three strings,
  *         or NULL if memory allocation fails.
  */
char	*ms_concat(const char *str1, const char *str2, const char *str3);

/**
  * @brief Evaluates user imput, creating tokens and running commands.
  *
  * @param shell The shell environment.
  */
void	ms_evaluate(t_shell *shell);

/**
  * @brief Displays the prompt, waits for user input, evaluates it and repeats.
  *
  * @param shell The shell environment.
  */
void	ms_read_loop(t_shell *shell);

/**
  * @brief Determines if running a built-in or an external command.
  *
  * @param shell The shell environment.
  */
void	ms_run_command(t_shell *shell);

/**
  * @brief Creates a new token with the data passed through parameters.
  *
  * @param type Category of the new token.
  * @param lexeme The token content, a dynamically allocated string.
  *
  * @return If success, returns a dynamically allocated token.
  *         If memory allocation fails, 
  *         or "lexeme" is not pointing to a valid memory location, 
  *         returns NULL.
  */
t_token	*ms_create_token(t_token_type type, char *lexeme);

/**
  * @brief Adds a token to a list of tokens.
  *
  * @param tokens The list in which the token will be pushed to.
  * @param new The token that will be added.
  */
void	ms_push_token(t_token_list *tokens, t_token *new);

/**
  * @brief Frees dynamic memory of all tokens in a list.
  *
  * @param tokens The list whose tokens will be freed.
  */
void	ms_free_tokens(t_token_list *tokens);

/**
  * @brief Frees dynamic memory of a list of tokens.
  *
  * @param tokens Double pointer to the list to be freed.
  *
  * This function also frees all the tokens in the list, 
  * and assigns the memory location of the list to NULL.
  */
void	ms_delete_tokens(t_token_list **tokens);

/**
  * @brief Adds a new token to a list of tokens.
  *
  * @param list The list of tokens.
  * @param type The type of the new token.
  * @param lexeme The lexeme of the new token.
  */
void	ms_append_token(t_token_list *list, t_token_type type, char *lexeme);

/**
  * @brief Checks that all tokens in a list are considered valid.
  *
  * @param tokens The token list to be checked.
  *
  * @return TRUE if all tokens are valid.
  *         FALSE if one or more tokens are not valid.
  *
  * It only checks tokens of type word.
  *
  * A token of type word is considered to be valid if 
  * in case of containing quotes, they are balanced.
  */
int		ms_are_tokens_valid(t_token_list *tokens);

/**
  * @brief Checks if a character is a whitespace.
  *
  * @param C The character to be checked.
  *
  * @return Non-zero value if the character is a whitespace.
  *         0 if the character is not a whitespace.
  */
int		ms_iswhitespace(const char c);

/**
  * @brief Checks if a character is a redirection.
  *
  * @param C The character to be checked.
  *
  * @return Non-zero value if the character is a redirection.
  *         0 if the character is not a redirection.
  */
int		ms_isredirection(const char c);

/**
  * @brief Checks if a token is a redirection.
  *
  * @param token The token to check.
  *
  * @return TRUE if is a redirection, FALSE otherwise.
  */
int		ms_is_redirtoken(t_token *token);

/**
  * @brief Checks if a character is a separator.
  *
  * @param C The character to be checked.
  *
  * @return Non-zero value if the character is a separator.
  *         0 if the character is not a separator.
  *
  * A separator includes: whitespaces, redirections, and pipes.
  */
int		ms_isseparator(const char c);

/**
  * @brief Checks if a string equals ">>".
  *
  * @param INPUT The string to be checked.
  *
  * @return Non-zero value if the string equals ">>".
  *         0 if the string is not equal to ">>".
  */
int		ms_isappend(const char *input);

/**
  * @brief Checks if a string equals "<<".
  *
  * @param C The string to be checked.
  *
  * @return Non-zero value if the string equals "<<".
  *         0 if the string is not equal to "<<".
  */
int		ms_isheredoc(const char *input);

/**
  * @brief Creates a word token read from user input.
  *
  * @param INPUT String read from stdin that contains the tokens to analyze.
  * @param tokens Where the new token will be pushed to.
  *
  * @return Length of the analyzed word.
  */
int		ms_analyze_word(const char *input, t_token_list *tokens);

/**
  * @brief Creates a redirection token read from user input.
  *
  * @param INPUT String read from stdin that contains the tokens to analyze.
  * @param tokens Where the new token will be pushed to.
  *
  * @return Length of the analyzed redirection.
  */
size_t	ms_analyze_redirection(const char *input, t_token_list *tokens);

/**
  * @brief Creates a pipe token read from user input.
  *
  * @param tokens Where the new token will be pushed to.
  *
  * @return Always 1.
  */
int		ms_analyze_pipe(t_token_list *tokens);

/**
  * @brief If lexemes are quoted, removes them.
  *
  * @param shell The shell environment.
  * 
  * This function iterates through all tokens, 
  * gets those that are of type word, 
  * and if their lexemes are single or double quoted, 
  * removes them.
  *
  * It also identifies single quoted tokens for variable expansion.
  */
void	ms_strip_quotes(t_shell *shell);

/**
  * @brief Gets the length of a variable expansion tag.
  *
  * @param lexeme Position where the '$' is.
  *
  * @return Length of variable expansion tag.
  *
  * If the variable expansion contains braces, includes them.
  * E.g. ${PATH} returns 7
  */
int		ms_get_var_len(const char *lexeme);

/**
  * @brief Gets the content of an environment variable.
  *
  * @param var_name Name of the variable.
  * @param shell The shell environment.
  *
  * @return Pointer to the variable.
  *
  * The returned string is dynamically allocated and must be freed.
  */
char	*ms_get_var_value(char *var_name, t_shell *shell);

/**
  * @brief Checks if a lexeme is a built-in command.
  *
  * @param lexeme The lexeme to be checked.
  *
  * @return TRUE if it's a built-in, FALSE otherwise.
  */
int		ms_is_builtin(const char *lexeme);

/**
  * @brief Runs a built-in command from a list of tokens.
  *
  * @param shell The shell env where the tokens are located.
  * @param lexeme A lexeme that may represent a built-in command.
  * @param is_child TRUE or FALSE.
  *
  * @return The return status of the built-in run, 
  *         or STD_RET_KO if the command does not run.
  */
int		ms_run_builtin(t_shell *shell, const char *lexeme, int is_child);

/**
  * @brief Changes the working directory, updating PWD and OLDPWD.
  *
  * @param shell The shell environment.
  *
  * @return STD_RET_OK if the working directory was changed,
  *         STD_RET_KO otherwise.
  */
int		ms_cd(t_shell *shell);

/**
  * @brief Prints all tokens separated by spaces, handling "-n" flag.
  *
  * @param shell The shell environment.
  *
  * @return Always STD_RET_OK.
  */
int		ms_echo(t_shell *shell);

/**
  * @brief Prints all environment variables.
  *
  * @param shell The shell environment.
  *
  * @return STD_RET_OK if the variables could be printed,
  *         or STD_RET_INCORRECT if unsupported tokens are found.
  */
int		ms_env(t_shell *shell);

/**
  * @brief Terminates minishell, it never returns.
  *
  * @param tokens The token list that will be freed.
  */
int		ms_exit(t_shell *shell);

/**
  * @brief Adds new environment variables or prints the existing ones.
  *
  * @param shell The shell environment.
  *
  * @return STD_RET_OK if all environment variables were added successfully, 
  *         STD_RET_KO otherwise.
  *
  * If the second token is NULL, prints all environment variables 
  * with a specific format.
  */
int		ms_export(t_shell *shell);

/**
  * @brief Prints the current directory using getcwd().
  *
  * @return STD_RET_OK if the directory was printed, 
  *         or STD_RET_KO if an error occurs.
  *
  * Uses PATH_MAX to define the buffer of the string that 
  * will contain the path to display.
  *
  * PATH_MAX is a constant that defines the maximum length 
  * of a file path on the system, it's defined in limits.h 
  * on most systems.
  */
int		ms_pwd(void);

/**
  * @brief Removes environment variables.
  *
  * @param shell The shell environment.
  *
  * @return STD_RET_OK if all environment variables were removed successfully, 
  *         STD_RET_KO otherwise.
  */
int		ms_unset(t_shell *shell);

/**
  * @brief Frees dynamic memory of shell environment.
  *
  * @param shell Shell whose environment will be freed.
  */
void	ms_free_env(t_shell *shell);

/**
  * @brief Copies the environment allocating dynamic memory in the process.
  *
  * @param shell Shell whose environment will be allocated for.
  * @param env Environment that will be copied from.
  */
void	ms_init_env(t_shell *shell, char **env);

/**
  * @brief Checks if the name of an environment variable is valid.
  *
  * @param name The name to be checked.
  * 
  * @return TRUE if the name is valid,
  *         FALSE otherwise.
  */
int		ms_is_validenv(const char *name);

/**
  * @brief Gets the value of an environment variable.
  *
  * @param shell The shell environment.
  *	@param name The tag of the variable to look for.
  *
  *	@return The environment variable.
  */
char	*ms_get_var(t_shell *shell, const char *name);

/**
  * @brief Gets the amount of environment variables.
  *
  * @param env The environment variables.
  *
  * @return Amount of environment variables.
  */
int		ms_envlen(char **env);

/**
  * @brief Adds a new variable to the shell environment.
  *
  * @param shell The shell environment.
  * @param name The tag of the new variable.
  * @param value The value of the new variable.
  *
  * @return EXIT_SUCCESS if the variable was added, 
  *         or EXIT_FAILURE if a memory allocation error occurs.
  */
int		ms_set_var(t_shell *shell, const char *name, const char *value);

/**
  * @brief Removes an existing variable from the shell environment.
  *
  * @param shell The shell environment.
  * @param name The tag of the existing variable.
  *
  * @return EXIT_SUCCESS if the variable was removed,
  *         or EXIT_FAILURE if a memory allocation error occurs.
  */
int		ms_unset_var(t_shell *shell, const char *name);

/**
  * @brief Runs an external command from a list of tokens.
  *
  * @param shell The shell env where the tokens are located.
  * @param lexeme A lexeme that may represent an external command.
  * @param is_child TRUE or FALSE.
  *
  * @return The return status of the command run, 
  *         or STD_RET_KO if the command does not run.
  */
int		ms_run_external(t_shell *shell, const char *lexeme, int is_child);

/**
  * @brief Converts a list of tokens to a list of strings.
  *
  * @param tokens The list of tokens to convert.
  *
  * @return A pointer to the dynamically allocated list of strings, 
  *         or NULL if memory allocation failed.
  */
char	**ms_to_argv(t_token_list *tokens);

/**
  * @brief Checks if a string is a path.
  *
  * @param str The string to be checked.
  *
  * @return A non-zero value if the string contains a slash,
  *         otherwise it returns 0.
  */
int		ms_is_path(const char *str);

/**
  * @brief Searches for a path in PATH environment variable.
  *
  * @param shell The shell environment.
  * @param cmd The command to look for.
  *
  * @return The path to the command or NULL if memory allocation fails.
  */
char	*ms_get_path(t_shell *shell, const char *cmd);

/**
  * @brief Frees a two-dimensional array of strings.
  *
  * @param str The array to free.
  */
void	ms_free_strings(char **str);

/**
  * @brief Gets the absolute path to the history file.
  *
  * @param shell The shell environment.
  *
  * @return A dynamically allocated string built 
  *         concatenating $PATH + "\" + FILE_HISTORY.
  *         If $PATH is not set, returns NULL.
  */
char	*ms_get_history_path(t_shell *shell);

/**
  * @brief If history file exists, loads history from it.
  *
  * @param shell The shell environment.
  */
void	ms_load_history(t_shell *shell);

/**
  * @brief Saves history to a file, creating it if needed.
  *
  * @param shell The shell environment.
  */
void	ms_save_history(t_shell *shell);

/**
  * @brief Frees allocated memory and readline resources.
  *
  * @param shell The shell environment.
  */
void	ms_free_resources(t_shell *shell);

/**
  * @brief Initializes an empty history.
  *
  * @param shell The shell environment.
  */
void	ms_init_history(t_shell *shell);

/**
  * @brief Adds the user input to the history.
  *
  * @param shell The shell environment.
  */
void	ms_add_history(t_shell *shell);

/**
  * @brief Initializes shell resources.
  *
  * @param shell The shell environment.
  * @param env The caller's environment variables.
  * @param cmd Path to minishell.
  */
void	ms_init_resources(t_shell *shell, char **env, char *cmd);

/**
  * @brief Prints an error message when a path is not found.
  *
  * @param cmd The rightmost part of a path.
  */
void	ms_not_found(const char *cmd);

/**
  * @brief Prints an error message when a resource can't be executed.
  *
  * @param cmd The rightmost part of a path.
  */
void	ms_permission_denied(const char *cmd);

/**
  * @brief Prints an error message when a path is a directory.
  *
  * @param cmd The rightmost part of a path.
  */
void	ms_is_a_directory(const char *cmd);

/**
  * @brief Checks if a path is valid for execution.
  *
  * @param cmd_path The absolute path to check.
  * @param lexeme The rightmost part of a path.
  *
  * @return STD_RET_OK if the path is valid.
  *         STD_RET_NOTFOUND if the path is not found.
  *         STD_RET_CANTEXEC if the path points to a directory, 
  *                          or lacks execution permissions.
  */
int		ms_is_path_valid(char *cmd_path, const char *lexeme);

/**
  * @brief Builds the prompt and returns a fallback if getcwd() fails.
  *
  * @return The prompt as a dynamically allocated string.
  */
char	*ms_get_prompt(void);

/**
  * @brief Prints an error message when an unexpected token is found.
  *
  * @param token The unexpected token.
  */
void	ms_syntax_error(const t_token *token);

/**
  * @brief Recalculates tail of shell environment.
  *
  * @param shell The shell environment.
  */
void	ms_recalc_tail(t_shell *shell);

/**
  * @brief Reads user input until a line with only "delimiter".
  *
  * @param delimiter A string that determines the end of user input.
  * 
  * @return A file descriptor to the content read from the user.
  *         Returns EXIT_FAILURE if an error occurs.
  */
int		ms_heredoc(char *delimiter);

/**
  * @brief Iterates through a list of redirs, applying them.
  *
  * @param list The list of redirs.
  * 
  * @return EXIT_SUCCESS if redirections are applied,
  *         EXIT_FAILURE if an error occurs.
  */
int		ms_apply_redirs(t_redir_list *list);

/**
  * @brief Reverts file descriptors from a list of redirs.
  *
  * @param list The list of redirs.
  */
void	ms_revert_redirs(t_redir_list *list);

/**
  * @brief Frees memory from a list of redirs.
  *
  * @param list The list of redirs.
  *
  * @return Always STD_RET_KO.
  */
int		ms_free_redirs(t_redir_list **list);

/**
  * @brief Gets a validated path.
  *
  * @param shell The shell environment.
  * @param lexeme The current lexeme.
  * @param error_code In case of failure, the error code is stored here.
  *
  * @return The path to "lexeme".
  */
char	*ms_get_valid_path(t_shell *shell, const char *lexeme, int *error_code);

/**
  * @brief Counts the amount of pipes in a list of tokens.
  *
  * @param list The list of tokens.
  *
  * @return The amount of pipes in the list.
  */
int		ms_count_pipes(t_token_list *list);

/**
  * @brief Frees a pipeline and each list of commands associated with it.
  *
  * @param pipeline The pipeline to be freed.
  */
void	ms_free_pipeline(t_pipeline **pipeline);

/**
  * @brief Gets a pipeline in the shell environment.
  *
  * @param shell The shell environment.
  *
  * @return EXIT_SUCCESS if the pipeline is retrieved, 
  *         EXIT_FAILURE if memory allocation errors occur.
  *
  * This function populates the t_shell with a pipeline, iterating 
  * through the list of tokens, extracting commands delimited by pipes.
  */
int		ms_get_pipeline(t_shell *shell);

/**
  * @brief Checks if a list of tokens contains a pipe.
  *
  * @param list The list of tokens.
  *
  * @return TRUE if the list has a pipe, FALSE otherwise.
  */
int		ms_has_pipe(t_token_list *list);

/**
  * @brief Runs commands from a pipeline swapping data streams.
  *
  * @param shell The shell environment.
  * @param pipeline The pipeline to run.
  *
  * @return The exit code of the last command of the pipeline if success, 
  *         or STD_RET_KO if an error occurs.
  */
int		ms_run_pipeline(t_shell *shell, t_pipeline *pipeline);

/**
  * @brief Encapsulates the logic to run a pipeline.
  *
  * @param shell The shell environment.
  */
void	ms_pipeline(t_shell *shell);

/**
  * @brief Verifies pipe syntax of a list of tokens.
  *
  * @param shell The shell environment.
  *
  * @return TRUE if the syntax is correct, FALSE otherwise.
  */
int		ms_is_pipesyntax_valid(t_shell *shell);

/**
  * @brief Frees resources from a child.
  *
  * @param shell The shell environment.
  */
void	ms_free_childres(t_shell *shell);

#endif
