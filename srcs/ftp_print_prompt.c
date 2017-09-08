/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_print_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 14:35:35 by ymukmar           #+#    #+#             */
/*   Updated: 2017/09/08 14:35:41 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	ftp_print_error(char *message, int fd)
{
	ft_putstr_fd(COLOR_RED, fd);
	ft_putendl_fd(message, fd);
	ft_putstr_fd(COLOR_RESET, fd);
}

void	ftp_print_success(char *message, int fd)
{
	ft_putstr_fd(COLOR_GREEN, fd);
	ft_putendl_fd(message, fd);
	ft_putstr_fd(COLOR_RESET, fd);
}

void	ftp_print_attempt(char *message, int fd)
{
	ft_putstr_fd(COLOR_YELLOW, fd);
	ft_putendl_fd(message, fd);
	ft_putstr_fd(COLOR_RESET, fd);
}
