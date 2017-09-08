/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_client_request.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:53:30 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/08 14:38:01 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int		ftp_valid_command(char *cmd)
{
	if (ft_strcmp(cmd, "ls") == 0 || ft_strcmp(cmd, "cd") == 0 ||
			ft_strcmp(cmd, "get") == 0 || ft_strcmp(cmd, "put") == 0 ||
			ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "quit") == 0)
		return (1);
	return (0);
}

static int		ftp_quit(char **args, int socketfd)
{
	if (ft_strcmp(args[0], "quit") == 0)
	{
		write(socketfd, args[0], ft_strlen(args[0]));
		ftp_print_success("GoodBye...", 1);
		close(socketfd);
		return (1);
	}
	return (0);
}

int				ftp_client_request(int socketfd, char *sendline)
{
	char	**args;
	char	server_res[BUFFER];

	args = ft_strsplit(sendline, ' ');
	ft_bzero(server_res, BUFFER);
	if (ftp_valid_command(args[0]))
	{
		if (ftp_quit(args, socketfd))
			return (0);
		write(socketfd, sendline, ft_strlen(sendline));
		if (ft_strcmp(args[0], "put") == 0)
			send_file(socketfd, args[1]);
		else if (ft_strcmp(args[0], "get") == 0)
			recv_file(socketfd, args[1]);
		read(socketfd, server_res, BUFFER);
		ft_putstr(server_res);
	}
	else
		ftp_print_error("Invalid command", 1);
	return (1);
}
