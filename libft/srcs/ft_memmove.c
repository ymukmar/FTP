/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 14:52:53 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/07 13:03:26 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*source;
	unsigned char	*dest;

	i = 0;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dest > source)
	{
		i = len - 1;
		while (i >= 0)
		{
			dest[i] = source[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
