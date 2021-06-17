/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_executable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:17:54 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 20:30:29 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_stat_nslash(struct stat *stats, char *args)
{
	if (stats->st_mode & S_IXUSR)
		return (args);
	else if (!(stats->st_mode & S_IXUSR))
		return (ft_write_string(args, ": Permission denied\n", 126));
	return (NULL);
}

char	*ft_path_no_nslash(char *args)
{
	struct stat	stats;
	char		*join;
	int			i;
	char		*path;

	i = 0;
	if (stat(args, &stats) == 0 && (sh.path[0] == NULL && is_f == 1))
		return (ft_stat_nslash(&stats, args));
	join = ft_strjoin("/", args);
	while (sh.path[i])
	{
		path = ft_strjoin(sh.path[i], join);
		if (stat(path, &stats) == 0)
		{
			if (stats.st_mode & S_IXUSR)
				return (ft_free2(path, join));
			else if (!(stats.st_mode & S_IXUSR))
				return (ft_free1(path, join));
			break ;
		}
		free(path);
		i++;
	}
	return (ft_free3(i, ret, join, args));
}

char	*ft_path_slash(char *args)
{
	struct stat	stats;

	if (stat(args, &stats) == 0)
	{
		if (S_ISDIR(stats.st_mode))
			return (ft_write_string(args, ": is a directory\n", 127));
		if (stats.st_mode & S_IXUSR)
			return (args);
		else if (!(stats.st_mode & S_IXUSR))
			return (ft_write_string(args, ": Permission denied\n", 126));
	}
	else
		return (ft_write_string(args, ": No such file or directory\n", 126));
	return (NULL);
}

char	*ft_path_nslash(char *args)
{
	struct stat	stats;

	if (stat(args, &stats) == 0)
	{
		if (stats.st_mode & S_IXUSR)
			return (args);
		else if (!(stats.st_mode & S_IXUSR))
			return (ft_write_string(args, ": Permission denied\n", 126));
	}
	else
		return (ft_write_string(args, ": No such file or directory\n", 127));
	return (NULL);
}

char	*ft_call_executable(char *args)
{
	int	i;

	i = 0;
	if (args[0] == '\0')
		return (ft_write_string(args, ": command not found\n", 127));
	if ((sh.path[0] != NULL && sh.path[0][0] != '\0')
			|| (sh.path[0] == NULL && is_f == 1))
	{
		if (ft_contain(args, '/') != -1)
			return (ft_path_no_slash(args));
		else if (ft_contain(args, '/') == -1)
			return (ft_path_no_nslash(args));
	}
	else if (sh.path[0] == NULL && is_f == -1)
	{
		if (ft_contain(args, '/') != -1)
			ft_path_slash(args);
		else if (ft_contain(args, '/') == -1)
			ft_path_nslash(args);
	}
	return (NULL);
}
