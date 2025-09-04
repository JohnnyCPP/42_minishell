/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_pf_int(va_list args, int *count)
{
	int		value;
	char	*string;
	int		length;

	value = va_arg(args, int);
	string = ft_itoa(value);
	if (!string)
		return ;
	ft_putstr_fd(string, 1);
	length = ft_strlen(string);
	*count += length;
	free(string);
}
