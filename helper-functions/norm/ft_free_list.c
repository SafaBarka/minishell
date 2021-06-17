/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:53:54 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/14 11:57:15 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_free_redirection(t_redirect *redirection)
{
	int	i;

	i = 0;
	while (redirection[i].file != NULL)
	{
		free(redirection[i].file);
		free(redirection[i].type);
		free(redirection[i].mask);
		i++;
	}
}

void	ft_free_space(t_split *space)
{
	t_split	*tmpspace;

	while (space != NULL)
	{
		tmpspace = space;
		space = space->next;
		free(tmpspace->str);
		free(tmpspace->mask);
		free(tmpspace);
	}
}

void	ft_free_pipe(t_split *pipe)
{
	t_split	*tmppipe;

	while (pipe != NULL)
	{
		tmppipe = pipe;
		if (tmppipe->redirections != NULL)
		{
			ft_free_redirection(tmppipe->redirections);
			free(tmppipe->redirections);
		}
		ft_free_space(pipe->split);
		pipe = pipe->next;
		free(tmppipe->str);
		free(tmppipe->mask);
		free(tmppipe);
	}
}

void	ft_free_list(void)
{
	t_split	*tmpsemicolon;

	while (sh.list != NULL)
	{
		tmpsemicolon = sh.list;
		ft_free_pipe(sh.list->split);
		sh.list = sh.list->next;
		free(tmpsemicolon->str);
		free(tmpsemicolon->mask);
		free(tmpsemicolon);
	}
}
