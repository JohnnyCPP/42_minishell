/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*ft_convert(int index, int sign, long value)
{
	char	*pointer;

	pointer = (char *) ft_calloc(index + 1, sizeof(char));
	if (!pointer)
		return ((void *) 0);
	if (sign < 0)
		pointer[0] = '-';
	index --;
	while (value)
	{
		pointer[index --] = (value % 10) + '0';
		value /= 10;
	}
	return (pointer);
}

static	int	ft_ltoa_len(long value)
{
	long	auxiliar;
	int		length;

	auxiliar = value;
	length = 0;
	while (auxiliar)
	{
		auxiliar /= 10;
		length ++;
	}
	return (length);
}

char	*ft_ltoa(long value)
{
	int		index;
	int		sign;

	if (!value)
		return (ft_strdup("0"));
	else if (value == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	index = ft_ltoa_len(value);
	sign = 1;
	if (value < 0)
	{
		index ++;
		sign *= -1;
		value *= -1;
	}
	return (ft_convert(index, sign, value));
}
