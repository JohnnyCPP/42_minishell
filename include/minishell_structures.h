/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_structures.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:18:15 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_STRUCTURES_H
# define MINISHELL_STRUCTURES_H

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APND,
	T_HEREDOC
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	int				is_singleq;
	char			*lexeme;
	struct s_token	*next;
}	t_token;

typedef struct s_token_list
{
	t_token	*head;
	t_token	*tail;
	int		length;
}	t_token_list;

typedef struct s_redir
{
	t_token_type	type;
	char			*filename;
}	t_redir;

typedef struct s_redir_list
{
	t_redir	*redirs;
	int		length;
	int		stdin;
	int		stdout;
}	t_redir_list;

typedef struct s_pipeline
{
	t_token_list	**commands;
	int				length;
}	t_pipeline;

typedef struct s_shell
{
	int				exit_code;
	int				child_stdin;
	int				child_stdout;
	char			*input;
	char			**env;
	char			**history;
	t_token_list	*tokens;
	t_pipeline		*pipeline;
}	t_shell;

#endif
