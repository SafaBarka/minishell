/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:27:26 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 15:39:11 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_nbr_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	ft_child_no_pipe(t_redirect *redirections, char **args)
{
	if (redirections != NULL)
	{
		if (ft_execute_redirections(redirections) == -1)
			exit(ret);
		else
		{
			sh.envp = array_export();
			execve(args[0], args, sh.envp);
		}
	}
	else
	{
		sh.envp = array_export();
		execve(args[0], args, sh.envp);
	}
}

void	ft_wait_no_pipe(void)
{
	var = 1;
	wait(&ret);
	if (WIFEXITED(ret))
	{
		ret = WEXITSTATUS(ret);
		replace_ret(export);
	}
}

int	ft_call(char **args, char **masks, t_redirect *redirections,
		t_split *current)
{
	int	out;
	int	in;
	int	id;

	out = dup(1);
	in = dup(0);
	if (args[0] != NULL && ft_is_builtin(args[0]))
	{
		if (ft_execute_builtin(args, current, masks, redirections) == -1)
			return (-1);
	}
	else
	{
		id = fork();
		v_fork++;
		if (id == 0)
			ft_child_no_pipe(redirections, args);
		ft_wait_no_pipe();
	}
	dup2(out, 1);
	dup2(in, 0);
	return (1);
}
