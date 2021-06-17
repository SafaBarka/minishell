/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_builtin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:41:18 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 15:46:57 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_redirections(t_redirect *redirections)
{
	if (ft_execute_redirections(redirections) == -1)
	{
		ft_write("No such file or directory\n");
		return (-1);
	}
	return (1);
}

int	ft_execute_builtin(char **args, t_split *current, char **masks,
		t_redirect *redirections)
{
	if (redirections != NULL && ft_execute_redirections(redirections) == -1)
		return (-1);
	if (ft_strncmp(args[0], "echo", 5) == 0)
		ft_echo(args, masks, ft_nbr_args(args), current);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		ft_add_export(args, masks, ft_nbr_args(args), current);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		ft_sort_env(ft_nbr_args(args), args);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		ft_pwd(ft_nbr_args(args));
	else if (ft_strncmp(args[0], "cd", 3) == 0)
		ft_cd(ft_nbr_args(args), args);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		ft_unset(args, ft_nbr_args(args));
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		ft_exit(ft_nbr_args(args), args);
	return (1);
}
