/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_contains_char(const char *chars, const char c)
{
	int	index;

	index = 0;
	while (chars[index])
		if (chars[index ++] == c)
			return (1);
	return (0);
}

static	int	ft_trim_start(const char *str, const char *chars)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (!ft_contains_char(chars, str[index]))
			break ;
		index ++;
	}
	return (index);
}

static	int	ft_trim_end(const char *str, const char *chars)
{
	int	index;

	index = ft_strlen(str) - 1;
	while (str[index] != 0)
	{
		if (!ft_contains_char(chars, str[index]))
			break ;
		index --;
	}
	return (index);
}

static	char	*ft_obtainstr(char *ptr1, char *ptr2)
{
	char	*result;
	int		index;

	index = 0;
	while (ptr1[index] != 0)
		if ((ptr1 + index ++) == ptr2)
			break ;
	index ++;
	result = (char *) ft_calloc(index, sizeof(char));
	ft_strlcpy(result, ptr1, index);
	return (result);
}

char	*ft_strtrim(const char *string, const char *characters)
{
	char	*ptr_start;
	char	*ptr_end;
	int		index;

	if (!string || !characters)
		return ((void *) 0);
	index = ft_trim_start(string, characters);
	ptr_start = (char *) string + index;
	index = ft_trim_end(string, characters);
	ptr_end = (char *) string + index;
	return (ft_obtainstr(ptr_start, ptr_end));
}
