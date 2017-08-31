/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:40:38 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/02 10:37:19 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t index;

	i = ft_strlen(s1);
	index = 0;
	while (s2[index] != '\0')
	{
		s1[i] = s2[index];
		i++;
		index++;
	}
	s1[i] = '\0';
	return (s1);
}
