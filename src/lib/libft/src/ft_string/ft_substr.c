/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_copy(char *dest, const char *source, int start, int length)
{
	int	index;

	index = 0;
	while (source[start + index] != 0 && length > 0)
	{
		dest[index] = source[start + index];
		index ++;
		length --;
	}
	dest[index] = 0;
}

static	char	*ft_allocate(const char *string, int start, int length)
{
	int		index;

	index = 0;
	while (string[start + index] != 0 && index < length)
		index ++;
	return ((char *) ft_calloc(index + 1, sizeof(char)));
}

char	*ft_substr(const char *string, unsigned int start, size_t length)
{
	char	*sub;

	if (!string)
		return ((void *) 0);
	sub = ft_allocate(string, (int) start, (int) length);
	if (sub == 0)
		return ((void *) 0);
	ft_copy(sub, string, (int) start, (int) length);
	return (sub);
}
