/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:20:46 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 15:42:41 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int		main(int argc, char **argv, char **environ)
{
	int					socketfd;
	int					client_socket;
	int					client_size;
	struct sockaddr_in	client;

	if (argc == 2)
	{
		g_environ = environ;	
		socketfd = ftp_server_init(argv[1]);
		client_size = sizeof(struct sockaddr_in);
		while (1)
		{
			if ((client_socket = accept(socketfd, (struct sockaddr *)&client,\
							(socklen_t *)&client_size)) > 0)
			{
				ftp_server_success("Client connected");
			}
		}
	}
	return (0);
}
