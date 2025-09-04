/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *string, int character)
{
	int		index;
	int		index_found;
	char	*aux_ptr_string;

	index = 0;
	index_found = -1;
	aux_ptr_string = (char *) string;
	while (string[index] != 0)
	{
		if (string[index] == character)
			index_found = index;
		index ++;
	}
	if (string[index] == character)
		return (aux_ptr_string + index);
	if (index_found != -1)
		return (aux_ptr_string + index_found);
	return ((void *) 0);
}
