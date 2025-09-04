/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_copy(char *destination, char *source, size_t length)
{
	size_t	index;

	index = 0;
	while (index < length)
	{
		destination[index] = source[index];
		index ++;
	}
}

static	void	ft_reverse_copy(char *destination, char *source, size_t length)
{
	while (length --)
		destination[length] = source[length];
}

void	*ft_memmove(void *destination, const void *source, size_t length)
{
	unsigned char	*aux_ptr_dest;
	unsigned char	*aux_ptr_src;

	if (!destination && !source)
		return (destination);
	aux_ptr_dest = (unsigned char *) destination;
	aux_ptr_src = (unsigned char *) source;
	if (destination > source)
		ft_reverse_copy((char *) aux_ptr_dest, (char *) aux_ptr_src, length);
	else
		ft_copy((char *) aux_ptr_dest, (char *) aux_ptr_src, length);
	return (destination);
}
