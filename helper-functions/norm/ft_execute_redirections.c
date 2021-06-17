/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:59:12 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 18:28:18 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_execute_redir(t_redirect *redirect, int i)
{
	char	*tmp;
	char	*mask;

	ft_remove_bq(&(redirect[i].file), &(redirect[i].mask));
	tmp = redirect[i].file;
	mask = redirect[i].mask;
	ft_replace_dollar(&(redirect[i].file), &(redirect[i].mask));
	if (ft_ambiguous(redirect, i, mask))
	{
		ft_write("minishell: ");
		ft_write(tmp);
		ft_write(": ambiguous redirect\n");
		return (-1);
	}
	if ((redirect[i].file)[0] == '\0')
	{
		ft_write("minishell: ");
		ft_write(redirect[i].file);
		ft_write(": No such file or directory\n");
		ret = 1;
		replace_ret(export);
		return (-1);
	}
	return (1);
}

int	ft_execute_out(t_redirect *redirect, int i, int *fd_out)
{
	if (ft_strncmp(redirect[i].type, "out", 4) == 0)
		*fd_out = open(redirect[i].file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else if (ft_strncmp(redirect[i].type, "append", 7) == 0)
		*fd_out = open(redirect[i].file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*fd_out == -1)
	{
		ft_write("minishell: ");
		ft_write(redirect[i].file);
		ft_write(": ");
		ft_write(strerror(errno));
		ft_write("\n");
		ret = 1;
		replace_ret(export);
		return (-1);
	}
	return (1);
}

int	ft_execute_in(t_redirect *redirect, int i, int *fd_in)
{
	*fd_in = open(redirect[i].file, O_RDONLY, 0644);
	if (*fd_in == -1)
	{
		ft_write("minishell: ");
		ft_write(redirect[i].file);
		ft_write(": ");
		ft_write(strerror(errno));
		ft_write("\n");
		ret = 1;
		replace_ret(export);
		return (-1);
	}
	return (1);
}

void	ft_execute_dup(int *fd_in, int *fd_out)
{
	if (*fd_in != -2 && *fd_in != -1)
	{
		dup2(*fd_in, 0);
		close(*fd_in);
	}
	if (*fd_out != -2 && *fd_out != -1)
	{
		dup2(*fd_out, 1);
		close(*fd_out);
	}
}

int	ft_execute_redirections(t_redirect *redirect)
{
	int	i;
	int	fd_out;
	int	fd_in;

	i = 0;
	fd_out = -2;
	fd_in = -2;
	while (redirect[i].file != NULL)
	{
		if (ft_execute_redir(redirect, i) == -1)
			return (-1);
		if ((ft_strncmp(redirect[i].type, "in", 3) != 0))
		{
			if (ft_execute_out(redirect, i, &fd_out) == -1)
				return (-1);
		}
		else
			if (ft_execute_in(redirect, i, &fd_in) == -1)
				return (-1);
		i++;
	}
	ft_execute_dup(&fd_in, &fd_out);
	return (1);
}
