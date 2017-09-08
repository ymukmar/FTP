/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 11:56:22 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/01 12:47:20 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_cat(int fd, int ofd)
{
	int		bytes;
	char	buffer[512];

	while ((bytes = read(fd, buffer, sizeof(buffer))))
	{
		if (bytes < 0)
			return (-1);
		write(ofd, &buffer, bytes);
	}
	return (0);
}
