/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(const char *string, char (*function)(unsigned int, char))
{
	unsigned int	index;
	char			*pointer;
	char			result;

	if (!string || !function)
		return ((void *) 0);
	index = 0;
	pointer = (char *) ft_calloc(ft_strlen(string) + 1, sizeof(char));
	while (string[index])
	{
		result = (*function)(index, string[index]);
		pointer[index ++] = result;
	}
	return (pointer);
}
