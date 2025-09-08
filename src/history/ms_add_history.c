/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_add_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

static	int	ms_histlen(t_shell *shell)
{
	int	i;

	if (!shell->history)
		return (0);
	i = 0;
	while (shell->history[i])
		i ++;
	return (i);
}

void	ms_add_history(t_shell *shell)
{
	char	**aux;
	int		histlen;
	int		i;

	if (!shell->input || !*shell->input)
		return ;
	histlen = ms_histlen(shell);
	aux = (char **) ft_calloc(histlen + 2, sizeof(char *));
	if (!aux)
		return ;
	i = 0;
	while (shell->history[i] && i < histlen)
	{
		aux[i] = ft_strdup(shell->history[i]);
		i ++;
	}
	aux[histlen] = ft_strdup(shell->input);
	aux[histlen + 1] = NULL;
	if (shell->history)
		ms_free_strings(shell->history);
	shell->history = aux;
}
