/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:36:51 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/15 11:45:56 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

t_split	*ft_lstnew(char *str, char *mask)
{
	t_split	*element;

	element = malloc(sizeof(t_split));
	if (!element)
		return (NULL);
	element->str = str;
	element->mask = mask;
	element->split = NULL;
	element->next = NULL;
	return (element);
}

t_split	*ft_lstlast(t_split *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstadd_back(t_split **alst, t_split *new)
{
	t_split	*lst;

	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
	}
}

int	ft_store_list(t_split **list, char *str, char *mask, t_store *store)
{
	t_split	*new;
	int		len;

	len = ft_strlen(str);
	if (str == NULL || mask == NULL)
		return (-1);
	new = ft_lstnew(str, mask);
	if (!new)
		return (-1);
	new->is_p = 0;
	if (store->c == '|' && store->len != len)
		new->is_p = 1;
	if (!(list))
		list = &new;
	else
		ft_lstadd_back(list, new);
	return (1);
}
