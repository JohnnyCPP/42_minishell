/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t length)
{
	size_t	destination_length;
	size_t	index;
	size_t	index_j;

	if (!destination || !source)
		return (0);
	destination_length = ft_strlen(destination);
	index = 0;
	index_j = destination_length;
	while (index_j + 1 < length)
	{
		destination[index_j] = source[index];
		index ++;
		index_j ++;
	}
	destination[index_j] = 0;
	return (destination_length + ft_strlen(source));
}
