/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_lower_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_pf_lower_hex_len(unsigned int value)
{
	int	length;

	length = 0;
	while (value)
	{
		length ++;
		value /= 16;
	}
	return (length);
}

static	void	ft_pf_lower_hex_print(unsigned int value)
{
	if (value >= 16)
	{
		ft_pf_lower_hex_print(value / 16);
		ft_pf_lower_hex_print(value % 16);
	}
	else if (value < 10)
		ft_putchar_fd(value + '0', 1);
	else
		ft_putchar_fd((value - 10) + 'a', 1);
}

void	ft_pf_lower_hex(va_list args, int *count)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	ft_pf_lower_hex_print(value);
	*count += ft_pf_lower_hex_len(value);
}
