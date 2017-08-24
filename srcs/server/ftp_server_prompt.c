/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_server_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:40:47 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 15:41:10 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void	ftp_server_error(char *message)
{
	ft_putstr(COLOR_RED);
	ft_putendl(message);
	ft_putstr(COLOR_RESET);
}

void	ftp_server_success(char *message)
{
	ft_putstr(COLOR_GREEN);
	ft_putendl(message);
	ft_putstr(COLOR_RESET);
}

void	ftp_server_attempt(char *message)
{
	ft_putstr(COLOR_YELLOW);
	ft_putendl(message);
	ft_putstr(COLOR_RESET);
}
