/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_dmin(const double a, const double b)
{
	if (a < b)
		return (a);
	return (b);
}

float	ft_fmin(const float a, const float b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_imin(const int a, const int b)
{
	if (a < b)
		return (a);
	return (b);
}
