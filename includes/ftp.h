/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:07:41 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/24 15:39:41 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FTP_H
# define _FTP_H

# include <stdio.h>
# include "libft.h" 

# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>

# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_RESET "\x1b[0m"

char		**g_environ;

/*
** FTP_CLIENT
*/

int			ftp_init_client(char *host, char *port);
int			ftp_client_request(int socket, char *line);
char		*ftp_gethostaddr(char *host);

/*
** FTP_CLIENT SUPPORT
*/

void		ftp_client_error(char *message);
void		ftp_client_success(char *message);
void		ftp_client_attempt(char *message);

/*
** FTP_SERVER
*/

int			ftp_server_init(char *port);

/*
** FTP_SERVER SUPPORT
*/

void		ftp_server_error(char *message);
void		ftp_server_success(char *message);
void		ftp_server_attempt(char *message);

#endif