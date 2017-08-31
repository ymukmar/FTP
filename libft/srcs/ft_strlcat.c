/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:07:41 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/03 15:58:44 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t x;
	size_t n;

	n = ft_strlen(dst);
	i = n;
	x = 0;
	if (size < n)
		return (ft_strlen(src) + size);
	if (size == n)
		return (ft_strlen(src) + n);
	while (src[x] && x < size - n - 1)
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (n + ft_strlen(src));
}
