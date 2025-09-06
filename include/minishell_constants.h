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

// application errors (perror)
# define ERR_SIGINT "signal (SIGINT)"
# define ERR_SIGQUIT "signal (SIGQUIT)"
# define ERR_GETCWD "getcwd"

// notifies the user of a successful termination
# define MSG_EXIT_SHELL "exit\n"

// notifies the user about invalid tokens
# define MSG_UNCL_QUOT "minishell: unclosed quotes in token: %s\n"

// notifies the user that the shell is ready to accept input
# define PROMPT "minishell> "

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
# define STD_RET_OK 0
# define STD_RET_KO 1
# define STD_RET_INCORRECT 2

// common environment variables
# define EVAR_HOME "HOME"
# define EVAR_OLDPWD "OLDPWD"
# define EVAR_PWD "PWD"

// used by cd to return to the previous path
# define PREV_PATH "-"

// used by export to print all environment variables
# define EXPORT_FMT_NOVAL "declare -x %s\n"
# define EXPORT_FMT "declare -x %s=\"%s\"\n"

#endif
