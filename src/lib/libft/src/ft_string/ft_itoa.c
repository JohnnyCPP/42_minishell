/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*ft_convert(int length, int sign, long absolute_value)
{
	char	*pointer;

	pointer = (char *) ft_calloc(length + 1, sizeof(char));
	if (!pointer)
		return (NULL);
	if (sign < 0)
		pointer[0] = '-';
	length --;
	while (absolute_value)
	{
		pointer[length] = (absolute_value % 10) + '0';
		absolute_value /= 10;
		length --;
	}
	return (pointer);
}

static	int	ft_itoa_len(int value)
{
	int		length;
	long	auxiliar;

	length = 0;
	if (value <= 0)
		length ++;
	auxiliar = value;
	if (auxiliar < 0)
		auxiliar *= -1;
	while (auxiliar)
	{
		auxiliar /= 10;
		length ++;
	}
	return (length);
}

char	*ft_itoa(int value)
{
	long	absolute_value;
	int		length;
	int		sign;

	if (!value)
		return (ft_strdup("0"));
	else if (value == INT_MIN)
		return (ft_strdup("-2147483648"));
	length = ft_itoa_len(value);
	if (value < 0)
	{
		sign = -1;
		absolute_value = -value;
	}
	else
	{
		sign = 1;
		absolute_value = value;
	}
	return (ft_convert(length, sign, absolute_value));
}
