/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_pf_show_pval(unsigned long value)
{
	if (value >= 16)
	{
		ft_pf_show_pval(value / 16);
		ft_pf_show_pval(value % 16);
	}
	else
	{
		if (value < 10)
			ft_putchar_fd(value + '0', 1);
		else if (value >= 10)
			ft_putchar_fd((value - 10) + 'a', 1);
	}
}

static	int	ft_pf_val_len(unsigned long value)
{
	int	i;

	i = 0;
	while (value)
	{
		value /= 16;
		i ++;
	}
	return (i);
}

void	ft_pf_ptr(va_list args, int *count)
{
	void				*pointer;
	unsigned long long	value;
	int					length;

	pointer = va_arg(args, void *);
	value = (unsigned long long) pointer;
	length = ft_pf_val_len(value);
	if (length == 0)
	{
		ft_putstr_fd(NULL_POINTER, 1);
		*count += ft_strlen(NULL_POINTER);
		return ;
	}
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_pf_show_pval(value);
	*count += (length + 2);
}
