/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:36:11 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/31 16:36:14 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int	is_command(char *cmd)
{
	if (ft_strcmp(cmd, "ls") == 0 || ft_strcmp(cmd, "cd") == 0 ||
			ft_strcmp(cmd, "get") == 0 || ft_strcmp(cmd, "put") == 0 ||
			ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "quit") == 0)
		return (1);
	return (0);
}

int	can_quit(char **args, int sockfd)
{
	if (ft_strcmp(args[0], "quit") == 0)
	{
		write(sockfd, args[0], strlen(args[0]));
		ft_putendl("Exiting ...");
		close(sockfd);
		return (1);
	}
	return (0);
}

int	request(int sockfd, char *sendline)
{
	char	**args;
	char	recvline[BUFFER];

	args = ft_strsplit(sendline, ' ');
	ft_bzero(recvline, BUFFER);
	if (is_command(args[0]))
	{
		if (can_quit(args, sockfd))
			return (0);
		write(sockfd, sendline, strlen(sendline));
		if (ft_strcmp(args[0], "put") == 0)
			send_file(sockfd, args[1]);
		else if (ft_strcmp(args[0], "get") == 0)
			recv_file(sockfd, args[1]);
		read(sockfd, recvline, BUFFER);
		ft_putstr(recvline);
	}
	else
	{
		ft_putstr(args[0]);
		ft_putendl(": invalid command");
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int				sockfd;
	char			*sendline;

	if (argc == 3)
	{
		sockfd = ftp_init_client(argv[1], argv[2]);
		while (1)
		{
			ft_putstr("$>");
			get_next_line(0, &sendline);
			if (ft_strcmp("", sendline) != 0)
				if (request(sockfd, sendline) == 0)
					return (1);
		}
	}
	else
		printf("Usage");
	return (0);
}
