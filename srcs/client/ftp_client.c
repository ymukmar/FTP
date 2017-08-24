/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:06:52 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 11:50:12 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"


int			main(int argc, char **argv)
{
	if (argc == 3)
	{
		int		socketfd;
		char	*sendline;
	
		sendline = NULL;
		socketfd = ftp_init_client(argv[1], argv[2]);
	}
	else
		ftp_client_error("Error Usage: ./client [host] [port]");
	return (0);
}
