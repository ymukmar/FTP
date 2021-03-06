/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 09:56:24 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/06 16:21:45 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t x;

	i = 0;
	x = ft_strlen(s1);
	while (s2[i] != '\0' && i < n)
	{
		s1[x] = s2[i];
		x++;
		i++;
	}
	s1[x] = '\0';
	return (s1);
}
