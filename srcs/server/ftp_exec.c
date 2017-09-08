/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 12:40:18 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/08 12:40:28 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	ftp_exec(char *in, int fd)
{
	char	*param[2];
	pid_t	p_id;
	char	**args;

	args = ft_strsplit(in, ' ');
    p_id = fork();
	if (valid_args(args, fd))
		return ;
	if (ft_strcmp(in, "ls") == 0)
		param[0] = "/bin/ls";
	else if (ft_strcmp(in, "pwd") == 0)
		param[0] = "/bin/pwd";
	param[1] = NULL;
    if (p_id == 0)
	{
		dup2(fd, 1);
		execv(param[0], param);
	}
}
