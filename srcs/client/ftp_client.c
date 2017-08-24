/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:06:52 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 16:13:13 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int			main(int argc, char **argv)
{
	int		socketfd;
	char	*sendline;
	
	if (argc == 3)
	{
		socketfd = ftp_init_client(argv[1], argv[2]);
		while (1)
		{
			ft_putstr("YSERVER>>> ");
			get_next_line(0, &sendline);
			if (ft_strcmp("", sendline) != 0)
				if (ftp_client_request(socketfd, sendline) == 0)
					return (1);
		}
	}
	else
		ftp_client_error("Error Usage: ./client [host] [port]");
	return (0);
}
