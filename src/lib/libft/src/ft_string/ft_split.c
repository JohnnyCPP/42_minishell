/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*ft_get_next_word(const char **str, const char delim)
{
	const char	*start;
	size_t		len;

	while (**str == delim)
		(*str)++;
	start = *str;
	len = 0;
	while (**str && **str != delim)
	{
		len ++;
		(*str)++;
	}
	return (ft_substr(start, 0, len));
}

static	int	ft_count_words(const char *str, const char delim)
{
	int	words;
	int	in_word;

	words = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != delim && !in_word)
		{
			in_word = 1;
			words ++;
		}
		else if (*str == delim)
			in_word = 0;
		str ++;
	}
	return (words);
}

void	ft_free_memory(char **split, int i)
{
	while (i -- > 0)
	{
		free(split[i]);
		split[i] = NULL;
	}
	free(split);
}

char	**ft_split(const char *str, const char delim)
{
	char	**split;
	int		words;
	int		i;

	if (!str || !*str)
		return (NULL);
	words = ft_count_words(str, delim);
	split = (char **) ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		split[i] = ft_get_next_word(&str, delim);
		if (!split[i])
		{
			ft_free_memory(split, i);
			return (NULL);
		}
		i ++;
	}
	split[i] = NULL;
	return (split);
}
