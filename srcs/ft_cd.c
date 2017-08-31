/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukmar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 16:35:11 by ymukmar           #+#    #+#             */
/*   Updated: 2017/08/31 16:35:14 by ymukmar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char	*ft_getenv(const char *name)
{
	char	**env;
	int		len;

	env = g_env;
	len = ft_strlen(name);
	while (*env)
	{
		if (ft_strncmp(*env, name, len) == 0)
			return (*env);
		env++;
	}
	return (NULL);
}

int		ft_chdir(char *newdir)
{
	if (chdir(newdir) != -1)
	{
		ft_setenv("OLDPWD", ft_strchr(ft_getenv("PWD"), '/'));
		ft_setenv("PWD", newdir);
		return (1);
	}
	return (0);
}

char	*get_newdir(char **args)
{
	char *newdir;

	if (args[1][0] == '~')
	{
		args[1]++;
		newdir = ft_strjoin(ft_strchr(ft_getenv("HOME"), '/'), args[1]);
	}
	else
	{
		if (args[1][0] == '/')
			newdir = args[1];
		else
		{
			newdir = ft_strjoin(ft_strchr(ft_getenv("PWD"), '/'), "/");
			newdir = ft_strjoin(newdir, args[1]);
		}
	}
	return (newdir);
}

void	ft_cd(char **args, int fd)
{
	char	*newdir;
	int		ch;

	ch = 0;
	if (args[1] == NULL || (args[1][0] == '~' && ft_strlen(args[1]) == 1))
		ch = ft_chdir(ft_strchr(ft_getenv("HOME"), '/'));
	else if (args[1][0] == '-')
		ch = ft_chdir(ft_strchr(ft_getenv("OLDPWD"), '/'));
	else if (args[1] && args[1][0] == '~')
	{
		newdir = get_newdir(args);
		ch = ft_chdir(newdir);
	}
	else
		ch = chdir(args[1]);
	if (ch == -1)
	{
		write(fd, "ERROR: no such file or directory\n", BUFFER);
		return ;
	}
	ft_putendl_fd("SUCCESS", fd);
}
