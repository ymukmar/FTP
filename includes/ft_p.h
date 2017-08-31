/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:15:48 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/31 16:34:34 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_P_H
# define _FT_P_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <arpa/inet.h>

# define COLOR_RED "\x1b[31m"
# define COLOR_GREEN "\x1b[32m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_RESET "\x1b[0m"

# define BUFFER 300
# define SEND_BUFF 256

typedef struct sockaddr_in	t_sockaddr_in;

char			**g_env;

/*
** FTP CLIENT
*/

int             ftp_init_client(char *host, char *port);
char            *ftp_gethostaddr(char *addr);
int             ftp_client_request(int socketfd, char *sendline);

/*
** FTP CLIENT SUPPORT
*/

void            ftp_client_success(char *message);
void            ftp_client_attempt(char *message);
void            ftp_client_error(char *message);

/*
** FTP
*/

char			*ft_getenv(const char *name);
void			ft_setenv(char *name, const char *value);
void			ft_cd(char **args, int fd);
int				send_file(int sock_fd, char *file);
void			recv_file(int sock_fd, char *file);
int				args_ok(int args, char *usage, int num, char **argv);

#endif
