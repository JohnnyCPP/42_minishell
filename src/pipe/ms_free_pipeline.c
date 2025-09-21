/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"

void	ms_free_pipeline(t_pipeline **pipeline)
{
	int	i;

	if (!pipeline || !*pipeline)
		return ;
	i = 0;
	while (i < (*pipeline)->length)
	{
		ms_delete_token_list(&(*pipeline)->commands[i]);
		i ++;
	}
	free((*pipeline)->commands);
	free(pipeline);
}
