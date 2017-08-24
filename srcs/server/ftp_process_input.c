/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_process_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:42:19 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 18:09:49 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	ftp_cd(char *args, int client_socket)
{
	write(client_socket, "cd fn", ft_strlen("cd fn"));
	write(client_socket, args, ft_strlen(args));
	return ;
}

void	ftp_put(char *args, int client_socket)
{
	write(client_socket, "put fn", ft_strlen("put fn"));
	write(client_socket, args, ft_strlen(args));
	return ;
}

void	ftp_get(char *args, int client_socket)
{
	write(client_socket, "get fn", ft_strlen("get fn"));
	write(client_socket, args, ft_strlen(args));
	return ;
}

void	ftp_process_input(char *request, int client_socket)
{
	char	**args;

	args = ft_strsplit(request, ' ');
	if (ft_strcmp(args[0], "cd") == 0)
		ftp_cd(args[0], client_socket);
	if (ft_strcmp(args[0], "put") == 0)
		ftp_put(args[1], client_socket);
	if (ft_strcmp(args[0], "get") == 0)
		ftp_get(args[1], client_socket);
	else
		write(client_socket, request, ft_strlen(request));
	return ;
}
