/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:35:56 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/31 16:36:00 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		has_args(char **args, int fd)
{
	char buff[SEND_BUFF];

	if (ft_strcmp(args[0], "cd") == 0)
	{
		ft_cd(args, fd);
		return (1);
	}
	if (ft_strcmp(args[0], "put") == 0)
	{
		recv_file(fd, args[1]);
		return (1);
	}
	if (ft_strcmp(args[0], "get") == 0)
	{
		if (send_file(fd, args[1]) == -1)
		{
			read(fd, buff, SEND_BUFF);
			write(fd, "ERROR", 5);
		}
		return (1);
	}
	return (0);
}

void	execin(char *in, int fd)
{
	char	*param[2];
	pid_t	p_id;
	char	**args;

	args = ft_strsplit(in, ' ');
	if (has_args(args, fd))
		return ;
	if (ft_strcmp(in, "ls") == 0)
		param[0] = "/bin/ls";
	else if (ft_strcmp(in, "pwd") == 0)
		param[0] = "/bin/pwd";
	param[1] = NULL;
	if ((p_id = fork()) == -1)
		ft_putendl("fork error");
	else if (p_id == 0)
	{
		dup2(fd, 1);
		execv(param[0], param);
		printf("Return not expected. Must be an execv error.n");
	}
}

void	con_client(int comm_fd, int listen_fd)
{
	pid_t	pid;
	char	str[BUFFER];

	pid = fork();
	if (pid < 0)
		ft_putendl("fork error");
	else if (pid == 0)
	{
		close(listen_fd);
		while (1)
		{
			ft_bzero(str, BUFFER);
			ft_putendl("Waiting for input ...");
			read(comm_fd, str, BUFFER);
			ft_putendl(str);
			if (ft_strcmp(str, "quit") == 0)
			{
				ft_putendl("Client disconnected.");
				exit(0);
			}
			execin(str, comm_fd);
		}
	}
	else
		close(comm_fd);
}

int		main(int argc, char **argv, char **envir)
{
	int				listen_fd;
	int				comm_fd;
	t_sockaddr_in	servaddr;

	if (!args_ok(argc, " [port]", 2, argv))
		return (1);
	g_env = envir;
	listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	ft_bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htons(INADDR_ANY);
	servaddr.sin_port = htons(ft_atoi(argv[1]));
	bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	ft_putendl("waiting for Connection ...");
	listen(listen_fd, 10);
	while (1)
	{
		comm_fd = accept(listen_fd, (struct sockaddr*)NULL, NULL);
		ft_putendl("Connection received!");
		con_client(comm_fd, listen_fd);
	}
	return (0);
}
