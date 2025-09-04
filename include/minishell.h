/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/07/15 02:49:28 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file minishell.h
 * @brief Contains function declarations for minishell.
 *
 * A minimalist Unix shell implementation written in C. 
 * It replicates core features of Bash, including command execution, 
 * pipes, redirections, environment variables, and signal handling.
 *
 * @author jonnavar & tdaroca
 * @version koala-0.7
 */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include "minishell_constants.h"
# include "minishell_structures.h"
# include "minishell_prototypes.h"
# include "minishell_long_prototypes.h"

#endif
