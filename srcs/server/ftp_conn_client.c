/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_conn_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:40:03 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/08 12:40:09 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	ftp_conn_client(int clientfd, int socketfd)
{
	pid_t	pid;
	char	str[BUFFER];

	pid = fork();
	if (pid == 0)
	{
		close(socketfd);
		while (1)
		{
			ft_bzero(str, BUFFER);
			ftp_print_attempt("Waiting for client input...", 1);
			read(clientfd, str, BUFFER);
			ft_putendl(str);
			if (ft_strcmp(str, "quit") == 0)
			{
				ftp_print_error("Client disconnected.", 1);
				exit(0);
			}
			ftp_exec(str, clientfd);
		}
	}
	else
		close(clientfd);
}
