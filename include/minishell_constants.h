/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_constants.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_CONSTANTS_H
# define MINISHELL_CONSTANTS_H

// application errors
# define ERR_ON_NL "Error: rl_on_new_line() returned -1\n"
# define ERR_REP_LN "Error: rl_replace_line() returned 1\n"
# define ERR_SIGINT "Sigaction (SIGINT)"
# define ERR_SIGQUIT "Sigaction (SIGQUIT)"

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

#endif
