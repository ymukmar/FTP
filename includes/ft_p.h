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

# define BUFFER 800
# define SEND_BUFF 500

char			**g_env;

/*
** FTP CLIENT
*/

int             ftp_init_client(char *host, char *port);
char            *ftp_gethostaddr(char *addr);
int             ftp_client_request(int socketfd, char *sendline);

/*
** FTP SERVER
*/

int		        ftp_server_init(char *port);
void	        ftp_conn_client(int clientfd, int socketfd);
void	        ftp_exec(char *in, int fd);
int		        valid_args(char **args, int fd);

/*
** FTP
*/

char			*ft_getenv(const char *name);
void			ft_setenv(char *name, const char *value);
void			ft_cd(char **args, int fd);
int				send_file(int sock_fd, char *file);
void			recv_file(int sock_fd, char *file);
int				args_ok(int args, char *usage, int num, char **argv);

/*
** FTP SUPPORT
*/

void            ftp_print_success(char *message, int fd);
void            ftp_print_attempt(char *message, int fd);
void            ftp_print_error(char *message, int fd);

#endif
