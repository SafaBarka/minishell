/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:37:55 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/15 11:40:52 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_exec(t_split **v)
{
	t_split	*semic;
	t_split	*pipe;

	semic = *v;
	while (semic)
	{
		pipe = semic->split;
		while (pipe)
		{
			if (pipe->is_p == 1)
			{
				if (ft_exec_pipe(pipe) != 1)
					return (ret);
				break ;
			}
			else if (pipe->is_p == 0)
				ft_exec_nopipe(pipe);
			pipe = pipe->next;
		}
		semic = semic->next;
	}
	return (1);
}
