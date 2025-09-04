/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       tdaroca <tdaroca@student.42madrid.com>   +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:02:01 by jonnavar          #+#    #+#             */
/*   Updated: 2025/08/22 17:39:30 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ms_iswhitespace(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ms_isredirection(const char c)
{
	return (c == '<' || c == '>');
}

int	ms_isseparator(const char c)
{
	int	iswhitespace;
	int	isredirection;
	int	ispipe;

	iswhitespace = ms_iswhitespace(c);
	isredirection = ms_isredirection(c);
	ispipe = c == '|';
	return (iswhitespace || isredirection || ispipe);
}
