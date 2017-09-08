/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_server_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:41:10 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/08 12:41:17 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		ftp_server_init(char *port)
{
	int					socketfd;
	int					portnum;
	struct sockaddr_in	server;

	portnum = ft_atoi(port);
	socketfd = socket(PF_INET, SOCK_STREAM, IPPROTO_IP);
	server.sin_family = AF_INET;
	server.sin_port = htons(portnum);
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	bind(socketfd, (const struct sockaddr *)&server, sizeof(server));
	listen(socketfd, 50);
	return (socketfd);
}
