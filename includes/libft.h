/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:34:52 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/31 16:34:55 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define BUFF_SIZE 10000000

char	*ft_strcpy(char * dst, const char * src);
size_t	ft_strlen(const char *s);
char	*ft_strncpy(char * dst, const char * src, size_t len);
char	*ft_strstr(const char *big, const char *little);
int		ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isalpha(int c);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int     ft_isascii(int c);
int     ft_isprint(int c);
void	ft_bzero(void *s, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	ft_putchar(char c);
void 	ft_putstr(char const *s);
void	*ft_memalloc(size_t size);
void	ft_memdel(void	**ap);
void	ft_strclr(char *s);
int		ft_strequ(char const *s1,char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_putendl(char const *s);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strnew(size_t size);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s);
void	ft_putnbr(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl_fd(char const *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
void	ft_strdel(char **as);
char	**ft_strsplit(char const *s, char c);
int		get_next_line(const int fd, char **line);

#endif
