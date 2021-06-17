/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:42:46 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 12:11:06 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_set_store(char *str, char *mask, char c, t_store *store)
{
	store->mask = mask;
	store->str = str;
	store->len = ft_strlen(str);
	store->count = ft_nbr_words(store->mask, store->len, c);
	store->c = c;
}

void	ft_is_redirection(t_split *pipe)
{
	if (ft_check_redirection(pipe->mask) != -1)
	{
		pipe->is_r = 1;
		ft_get_redirection(pipe);
	}
	else
	{
		pipe->redirections = NULL;
		pipe->is_r = 0;
	}
}

int	ft_call_split(t_split *semic, t_store *store, t_split *pipe)
{
	while (semic)
	{
		ft_set_store(semic->str, semic->mask, '|', store);
		if (!ft_split(&semic->split, store))
			return (-1);
		pipe = semic->split;
		while (pipe)
		{
			ft_is_redirection(pipe);
			ft_set_store(pipe->str, pipe->mask, 'S', store);
			if (!(ft_split(&pipe->split, store)))
				return (-1);
			pipe = pipe->next;
		}
		semic = semic->next;
	}
	return (1);
}

int	ft_store(t_split **head, char *line, char *mask)
{
	t_split	*semicolon;
	t_store	*store;
	t_split	*pipe;

	pipe = NULL;
	store = malloc(sizeof(t_store));
	if (!store)
		return (-1);
	ft_set_store(line, mask, ';', store);
	if (!ft_split(head, store))
		return (-1);
	semicolon = *head;
	if (!ft_call_split(semicolon, store, pipe))
		return (-1);
	free(store);
	return (1);
}
