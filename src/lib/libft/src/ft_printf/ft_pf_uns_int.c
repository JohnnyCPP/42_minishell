/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_uns_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	char	*ft_pf_tostr(unsigned int value, int length)
{
	char	*result;

	result = (char *) ft_calloc(length + 1, sizeof(char));
	if (!result)
		return (0);
	result[length] = '\0';
	while (value)
	{
		result[length - 1] = (value % 10) + 48;
		value /= 10;
		length --;
	}
	return (result);
}

static	int	ft_pf_uns_int_len(unsigned int value)
{
	int	length;

	length = 0;
	while (value != 0)
	{
		value /= 10;
		length ++;
	}
	return (length);
}

void	ft_pf_uns_int(va_list args, int *count)
{
	unsigned int		value;
	char				*string;
	int					length;

	value = va_arg(args, unsigned int);
	if (value == 0)
	{
		ft_putchar_fd('0', 1);
		(*count)++;
		return ;
	}
	length = ft_pf_uns_int_len(value);
	string = ft_pf_tostr(value, length);
	ft_putstr_fd(string, 1);
	*count += ft_strlen(string);
	free(string);
}
