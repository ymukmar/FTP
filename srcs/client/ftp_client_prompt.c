/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_client_prompt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:52:29 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 11:57:28 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	ftp_client_error(char *message)
{
	ft_putstr(COLOR_RED);
	ft_putendl(message);
	ft_putstr(COLOR_RESET);
}

void	ftp_client_success(char *message)
{
	ft_putstr(COLOR_GREEN);
	ft_putendl(message);
	ft_putstr(COLOR_RESET);
}

void	ftp_client_attempt(char *message)
{
	ft_putstr(COLOR_YELLOW);
	ft_putendl(message);
	ft_putstr(COLOR_RESET);
}
