/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_gethostaddr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:45:55 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 11:51:36 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

char	*ftp_gethostaddr(char *addr)
{
	int				i;
	char			*ip;
	struct hostent	*he;
	struct in_addr	**addr_list;

	i = 0;
	ip = (char *)malloc(sizeof(char) * 100);
	if ((he = gethostbyname(addr)) != NULL)
	{
		addr_list = (struct in_addr **)he->h_addr_list;
		while (addr_list[i] != NULL)
		{
			ft_strcpy(ip, inet_ntoa(*addr_list[i]));
			i++;
		}
	}
	else
		return (addr);
	return (ip);
}
