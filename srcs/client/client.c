/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:36:11 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/08 14:36:55 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	ftp_cat(void)
{
	int		fd;

	if ((fd = open("./etc/FILE_TRANSFER_PROTOCOL", O_RDONLY)) != -1)
	{
		ft_putstr(COLOR_GREEN);
		ft_cat(fd, 1);
		ft_putendl(COLOR_RESET);
	}
	else
		ft_putendl("Open failed");
}

int		main(int argc, char **argv)
{
	int				socketfd;
	char			*sendline;

	if (argc == 3)
	{
		socketfd = ftp_init_client(argv[1], argv[2]);
		ftp_cat();
		while (1)
		{
			ft_putstr("$> ");
			get_next_line(0, &sendline);
			if (ft_strcmp("", sendline) != 0)
				if (ftp_client_request(socketfd, sendline) == 0)
					return (1);
		}
	}
	else
		ftp_print_error("ERROR Usage: ./client localhost 4500", 1);
	return (0);
}
