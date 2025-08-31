/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*       cvicol <cvicol@student.42madrid.com>     +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *string, const char *to_join)
{
	char	*pointer;
	size_t	length;
	size_t	join_length;

	if (!string || !to_join)
		return ((void *) 0);
	length = ft_strlen(string);
	join_length = ft_strlen(to_join);
	pointer = (char *) ft_calloc(length + join_length, sizeof(char));
	if (!pointer)
		return ((void *) 0);
	ft_memcpy(pointer, string, length);
	ft_memcpy(pointer + length, to_join, join_length);
	return (pointer);
}
