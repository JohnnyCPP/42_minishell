/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_islhex(const char character)
{
	if ('a' <= character && character <= 'f')
		return (1);
	else if (ft_isdigit(character))
		return (1);
	return (0);
}

int	ft_isuhex(const char character)
{
	if ('A' <= character && character <= 'F')
		return (1);
	else if (ft_isdigit(character))
		return (1);
	return (0);
}

int	ft_ishex(const char character)
{
	if (ft_isdigit(character))
		return (1);
	else if (ft_islhex(character) || ft_isuhex(character))
		return (1);
	return (0);
}
