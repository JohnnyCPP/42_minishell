/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_bit_split(const char *binary, char *res, int bin_len)
{
	int		bit_index;
	int		result_index;

	bit_index = 0;
	result_index = 0;
	while (*(binary + bit_index))
	{
		res[result_index] = binary[bit_index];
		(result_index)++;
		(bit_index)++;
		if (bit_index < bin_len && bit_index % 4 == 0)
		{
			res[result_index] = ' ';
			(result_index)++;
		}
	}
	res[result_index] = '\0';
}

int	ft_split_binary_free(char **binary)
{
	int		nibbles;
	size_t	binary_length;
	char	*result;

	if (!binary || !*binary)
		return (0);
	binary_length = ft_strlen(*binary);
	if (!ft_isbinarystr(*binary) || binary_length % 4 != 0)
		return (0);
	nibbles = binary_length / 4;
	result = (char *) ft_calloc(binary_length + nibbles, sizeof(char));
	if (!result)
		return (0);
	ft_bit_split(*binary, result, binary_length);
	free(*binary);
	*binary = result;
	return (1);
}

char	*ft_split_binary_copy(const char *binary)
{
	int		nibbles;
	size_t	binary_length;
	char	*result;

	if (!binary)
		return (NULL);
	binary_length = ft_strlen(binary);
	if (!ft_isbinarystr(binary) || binary_length % 4 != 0)
		return (NULL);
	nibbles = binary_length / 4;
	result = (char *) ft_calloc(binary_length + nibbles, sizeof(char));
	if (!result)
		return (NULL);
	ft_bit_split(binary, result, binary_length);
	return (result);
}
