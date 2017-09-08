
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