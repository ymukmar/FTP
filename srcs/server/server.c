/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:35:56 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/08 12:39:58 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		main(int argc, char **argv, char **environ)
{
	int				socketfd;
	int				clientfd;

	if (argc == 2)
	{
		g_env = environ;
		socketfd = ftp_server_init(argv[1]);
		while (1)
		{
			clientfd = accept(socketfd, (struct sockaddr*)NULL, NULL);
			ftp_print_success("Client Connected", 1);
			ftp_conn_client(clientfd, socketfd);
		}
	}
	else
		ftp_print_error("ERROR Incorrect Usage", 1);
	return (0);
}
