/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_nopipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:15:30 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 18:21:40 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_nbr_space(t_split *split)
{
	int	i;

	i = 0;
	while (split)
	{
		if (ft_contain(split->mask, 'O') == -1)
			i++;
		split = split->next;
	}
	return (i);
}

void	ft_fill_args_np(t_npipe *np, t_split *pi)
{
	np->args = malloc(sizeof(char *));
	np->masks = malloc(sizeof(char *));
	(np->args)[0] = NULL;
	(np->masks)[0] = NULL;
	np->space = pi->split;
	while (np->space)
	{
		ft_remove_bq(&(np->space)->str, &(np->space)->mask);
		ft_replace_dollar_exec(&(np->space)->str, &(np->space)->mask);
		ft_fill(&(np->args), &(np->masks), (np->space)->str, (np->space)->mask);
		np->space = (np->space)->next;
	}
}

int	ft_fill_executable(t_npipe *np, t_split *pi)
{
	np->tmp = (np->args)[0];
	(np->args)[0] = ft_call_executable((np->args)[0]);
	if (np->tmp != (np->args)[0])
		free(np->tmp);
	if (!((np->args)[0]))
	{
		ft_free_double(np->args);
		ft_free_double(np->masks);
		return (-1);
	}
	return (1);
}

int	ft_exec_nopipe(t_split *pi)
{
	t_npipe	np;

	np.args = NULL;
	np.masks = NULL;
	ft_fill_args_np(&np, pi);
	if ((np.args)[0] != NULL)
	{
		if (ft_is_builtin(np.args[0]) == 0)
		{
			if (ft_fill_executable(&np, pi) == -1)
				return (-1);
		}
	}
	if (ft_call(np.args, np.masks, pi->redirections, pi->split) == -1)
	{
		ft_free_double(np.args);
		ft_free_double(np.masks);
		return (-1);
	}
	ft_free_double(np.masks);
	ft_free_double(np.args);
	return (1);
}
