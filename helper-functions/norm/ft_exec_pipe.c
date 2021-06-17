/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:53:53 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 15:23:08 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_nbr_pipe(t_split *pipe)
{
	int		i;
	t_split	*current;

	current = pipe;
	i = 0;
	while (current)
	{
		if (current->is_p == 1)
			current = current->next;
		i++;
	}
	return (i - 1);
}

void	ft_builtin_cmd(char **args, t_split *current, char **masks)
{
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
}

int	ft_fill_args(t_pipe *p)
{
	char	*tmp;

	ft_fill_space(p);
	if (p->args[0] != NULL)
	{
		if (ft_strncmp(p->args[0], "cd", 3) != 0
			&& ft_strncmp(p->args[0], "pwd", 4) != 0
			&& ft_strncmp(p->args[0], "export", 7) != 0
			&& ft_strncmp(p->args[0], "unset", 6) != 0
			&& ft_strncmp(p->args[0], "env", 4) != 0
			&& ft_strncmp(p->args[0], "exit", 5) != 0
			&& ft_strncmp(p->args[0], "echo", 5) != 0)
		{
			tmp = p->args[0];
			p->args[0] = ft_call_executable(p->args[0]);
			free(tmp);
			if (!p->args[0])
				return (127);
		}
	}
	return (1);
}

void	ft_parse_pipe(t_pipe *p, t_split *head)
{
	while (p->nbr >= 0)
	{
		p->args = malloc(sizeof(char *));
		p->masks = malloc(sizeof(char *));
		p->args[0] = NULL;
		p->masks[0] = NULL;
		ft_fill_args(p);
		if (p->nbr != 0)
			pipe(p->fd);
		p->pid = fork();
		v_fork++;
		p->f++;
		if (p->pid == 0)
			ft_child(p, head);
		close(p->fd[1]);
		p->fd_old = p->fd_in;
		if (p->fd_old != 0 && p->fd_old != 1)
			close(p->fd_old);
		p->fd_in = p->fd[0];
		p->nbr--;
		p->current = (p->current)->next;
		ft_free_double(p->args);
		ft_free_double(p->masks);
	}
}

int	ft_exec_pipe(t_split *head)
{
	t_pipe	p;

	p.nbrsplit = 0;
	p.nbr = ft_nbr_pipe(head);
	p.fd_in = 0;
	p.current = head;
	p.fd_in = 0;
	p.f = 0;
	ft_parse_pipe(&p, head);
	ft_wait_child(&p);
	return (1);
}
