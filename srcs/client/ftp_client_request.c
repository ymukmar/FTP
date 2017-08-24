/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_client_request.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:19:56 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 16:34:38 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

int		ftp_client_request(int socketfd, char *line)
{
	char	**args;
	char	server_res[BUFFER];

	args = ft_strsplit(line, ' ');
	ft_bzero(server_res, BUFFER);
	write(socketfd, line, ft_strlen(line));
	read(socketfd, server_res, BUFFER);
	ft_putendl(server_res);
	return (1);
}
