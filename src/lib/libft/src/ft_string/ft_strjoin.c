/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:05:07 by jonnavar          #+#    #+#             */
/*   Updated: 2025/04/29 23:05:34 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *dest, const char *src)
{
	char	*strjoin;
	size_t	dest_len;
	size_t	src_len;

	if (!dest || !src)
		return (NULL);
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	strjoin = (char *) ft_calloc(dest_len + src_len + 1, sizeof(char));
	if (!strjoin)
		return (NULL);
	ft_memcpy(strjoin, dest, dest_len);
	ft_memcpy(strjoin + dest_len, src, src_len);
	return (strjoin);
}
