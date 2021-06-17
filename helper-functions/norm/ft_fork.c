/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:56:07 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 14:11:19 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_fill_space(t_pipe *p)
{
	p->space = p->current->split;
	while (p->space)
	{
		ft_remove_bq(&(p->space)->str, &(p->space)->mask);
		ft_replace_dollar_exec(&(p->space)->str, &(p->space)->mask);
		ft_fill(&(p->args), &(p->masks), (p->space)->str, (p->space)->mask);
		p->space = (p->space)->next;
	}
}

void	ft_child(t_pipe *p, t_split *head)
{
	if (p->args[0] == NULL)
		exit(ret);
	dup2(p->fd_in, 0);
	if ((p->current)->next != NULL)
	{
		dup2(p->fd[1], 1);
		close(p->fd[1]);
	}
	close(p->fd[0]);
	if ((p->current)->redirections != NULL)
	{
		if (ft_execute_redirections((p->current)->redirections) == -1)
			exit(0);
	}
	if (ft_is_builtin(p->args[0]))
	{
		ft_builtin_cmd(p->args, head->split, p->masks);
		exit(0);
	}
	else
	{
		sh.envp = array_export();
		execve(p->args[0], p->args, sh.envp);
	}
}

void	ft_wait_child(t_pipe *p)
{
	while (p->f > 0)
	{
		p->f--;
		var = 1;
		wait(&ret);
		if (WIFEXITED(ret))
		{
			ret = WEXITSTATUS(ret);
			replace_ret(export);
		}
	}
}
