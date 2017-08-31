/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_init_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:45:27 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/31 16:36:19 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		ftp_init_client(char *host, char *port)
{
	int					socketfd;
	int					portnum;
	char				*hostaddr;
	struct sockaddr_in	server;

	socketfd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
	hostaddr = ftp_gethostaddr(host);
	portnum = ft_atoi(port);
	server.sin_family = AF_INET;
	server.sin_port = htons(portnum);
	server.sin_addr.s_addr = inet_addr(hostaddr);
	ftp_client_attempt("Attempting Server connection...");
	if (connect(socketfd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		ftp_client_error("Error: Failed to Connect to server");
		exit(EXIT_FAILURE);
	}
	free(hostaddr);
	return (socketfd);
}
