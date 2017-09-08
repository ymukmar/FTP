/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_valid_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:41:31 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/08 12:41:37 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int		valid_args(char **args, int fd)
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
			ftp_print_error("Error: GET failed", fd);
		}
		return (1);
	}
	return (0);
}
