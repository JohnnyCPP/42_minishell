/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	void	ft_pf_ph(char ph, va_list args, int *i, int *count)
{
	if (ph == '-' || ft_isdigit(ph) || ph == '.')
		ft_pf_ph_default(i, count);
	else if (ph == 'c' || ph == 's' || ph == 'p')
		ft_pf_ph_str(ph, args, i, count);
	else if (ph == 'd' || ph == 'i' || ph == 'u')
		ft_pf_ph_int(ph, args, i, count);
	else if (ph == 'l')
		ft_pf_ph_long(ph, args, i, count);
	else if (ph == '%')
		ft_pf_ph_percentage(i, count);
	else if (ph == 'x' || ph == 'X')
		ft_pf_ph_base(ph, args, i, count);
	else
		ft_pf_ph_default(i, count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			ft_pf_ph(format[i + 1], args, &i, &count);
		else
		{
			ft_putchar_fd(format[i], 1);
			i ++;
			count ++;
		}
	}
	va_end(args);
	return (count);
}
