/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:14:09 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/06 16:30:14 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ch;
	size_t	len;

	i = 0;
	ch = (char *)s;
	len = ft_strlen(ch) + 1;
	while (i < len)
	{
		if (ch[i] == (unsigned char)c)
			return (ch + i);
		i++;
	}
	return (NULL);
}
