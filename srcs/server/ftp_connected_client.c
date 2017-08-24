/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_connected_client.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:51:32 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 17:35:28 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	ftp_connected_client(int client_socket, int socketfd)
{
	pid_t	pid;
	char	request[BUFFER];

	pid = fork();
	socketfd = 0;
	if (pid == 0)
	{
		while (read(client_socket, request, BUFFER))
		{
			printf("Cliend [%d] asked for %s\n", client_socket, request);
			ftp_process_input(request, client_socket);
			ft_bzero(request, BUFFER);
		}
		ftp_server_error("Client disconnected");
	}
}
