/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 08:59:34 by nsikhosa          #+#    #+#             */
/*   Updated: 2017/06/10 13:06:13 by nsikhosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*temp;

	temp = malloc(sizeof(*temp) * size);
	if (!temp || !size)
		return (NULL);
	temp = ft_memset(temp, 0, size);
	return (temp);
}
