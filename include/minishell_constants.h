/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_constants.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_CONSTANTS_H
# define MINISHELL_CONSTANTS_H

// application errors (write)
# define ERR_ON_NL "Error: rl_on_new_line() returned -1\n"
# define ERR_ENV "Error: unexpected token: "
# define ERR_EXPORT_HEAD "Error: `"
# define ERR_EXPORT_TAIL "': not a valid identifier\n"
# define ERR_OLDPWD "Error: OLDPWD not set\n"
# define ERR_HOME "Error: HOME not set\n"
# define ERR_SYNTAX_HEAD "Error: syntax error near unexpected token `"
# define ERR_SYNTAX_TAIL "'\n"
# define ERR_EXECVE_HEAD "Error: "
# define ERR_EXECVE_TAIL ": no such file or directory\n"
# define ERR_PERM_DENIED ": permission denied\n"
# define ERR_IS_DIRECTORY ": is a directory\n"
# define ERR_EXIT_ARGS "Error: exit: too many arguments\n"
# define ERR_EXIT_NUMARG_HEAD "Error: exit: "
# define ERR_EXIT_NUMARG_TAIL ": numeric argument required\n"
# define ERR_CMD_NOTFOUND_HEAD "Error: " 
# define ERR_CMD_NOTFOUND_TAIL ": command not found\n"

// application errors (perror)
# define ERR_SIGINT "signal (SIGINT)"
# define ERR_SIGQUIT "signal (SIGQUIT)"
# define ERR_GETCWD "getcwd"
# define ERR_EXECVE "execve"
# define ERR_WAITPID "waitpid"
# define ERR_PIPE "pipe"

// notifies the user that exit() was executed
# define MSG_EXIT_SHELL "exit\n"

// notifies the user about invalid tokens
# define MSG_UNCL_QUOT "minishell: unclosed quotes in token: %s\n"

// notifies the user that the shell is ready to accept input
// it's used when getcwd() fails
# define FALLBACK_PROMPT "minishell-1.0$ "

// appended to getcwd() and used as prompt
# define PROMPT_TAIL " $ "

// used for infinite loop and return values
# define TRUE 1
# define FALSE 0

// when the repl iterates, sets signal value to zero
# define SIGNAL_RESET 0

// used for rl_replace_line() second parameter
# define CLEAR_UNDO_LIST 1

// used for functions whose return failure is -1 by convention
# define FAIL -1

// define redirections used during lexical analysis
# define APPND_STR ">>"
# define HEREDOC_STR "<<"
# define REDIROUT_STR ">"
# define REDIRIN_STR "<"

// define builtins
# define CMD_CD "cd"
# define CMD_ECHO "echo"
# define CMD_ENV "env"
# define CMD_EXIT "exit"
# define CMD_EXPORT "export"
# define CMD_PWD "pwd"
# define CMD_UNSET "unset"

// standard return values for commands
// 0 = success
// 1 = general error
// 2 = specific errors (e.g. cd with too many args)
// 126 = the command was found, but it is not executable (or a directory)
// 127 = the command could not be found
# define STD_RET_OK 0
# define STD_RET_KO 1
# define STD_RET_INCORRECT 2
# define STD_RET_CANTEXEC 126
# define STD_RET_NOTFOUND 127

// common environment variables
# define EVAR_HOME "HOME"
# define EVAR_OLDPWD "OLDPWD"
# define EVAR_PATH "PATH"
# define EVAR_PWD "PWD"
# define EVAR_SHELL "SHELL"

// used by cd to return to the previous path
# define PREV_PATH "-"

// used by export to print all environment variables
# define EXPORT_FMT_NOVAL "declare -x %s\n"
# define EXPORT_FMT "declare -x %s=\"%s\"\n"

// a child process id is zero
# define PROC_CHILD 0

// used with waitpid()
# define NO_OPTIONS 0

// configures the behavior of waitpid()
// 0 = wait for the child to die
# define WAIT_FOR_CHILD 0

// used by history functionality to persist history across sessions
# define FILE_HISTORY ".minishell_history"

// used by readline() to wait for input during heredoc
# define HEREDOC_PROMPT "> "

// used by pipe() to create an IPC channel
# define PIPE_FD_AMOUNT 2
# define PIPE_WRITE_END 1
# define PIPE_READ_END 0

// returned by open() when a file does not exist
# define DOES_NOT_EXIST -1

// default value for the fd of a redirection
# define NO_FILE_DESCRIPTOR -1

// used by open() to create a new history file and for redirections
# define MODE_RW 0644

// used to drive the repl loop
# define ACT_BREAK "break"
# define ACT_CONTINUE "continue"

// used to drive the heredoc loop
# define HEREDOC_CONTINUE 0
# define HEREDOC_END 1
# define READLINE_FINISHED 1
# define READLINE_NOT_FINISHED 0

// used by ms_redir_errors() when a syntax error occurs
# define DEFAULT_LEXEME "newline"

// used by exit to validate args amount
# define EXIT_TOKEN_LIMIT 2

#endif
