/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:07:26 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 20:17:37 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_write_string(char *args, char *message, int i)
{
	ft_write("minishell: ");
	ft_write(args);
	ft_write(message);
	ret = i;
	replace_ret(export);
	return (NULL);
}

char	*ft_path_no_slash(char *args)
{
	struct stat	stats;

	if (stat(args, &stats) == 0)
	{
		if (S_ISDIR(stats.st_mode))
			return (ft_write_string(args, ": is a directory\n", 126));
		else if (stats.st_mode & S_IXUSR)
			return (args);
		else if (!(stats.st_mode & S_IXUSR))
			return (ft_write_string(args, ": Permission denied\n", 126));
	}
	else
		return (ft_write_string(args, ": No such file or directory\n", 127));
	return (NULL);
}

char	*ft_free1(char *path, char *join)
{
	ft_write("minishell: ");
	ft_write(path);
	ft_write(": Permission denied\n");
	ret = 126;
	replace_ret(export);
	free(join);
	free(path);
	return (NULL);
}

char	*ft_free2(char *path, char *join)
{
	free(join);
	return (path);
}

char	*ft_free3(int i, int ret, char *join, char *args)
{
	free(join);
	if (sh.path[i] == NULL)
		return (ft_write_string(args, ": command not found\n", 127));
	return (NULL);
}
