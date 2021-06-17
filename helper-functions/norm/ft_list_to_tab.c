/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:35:08 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 18:52:00 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_lstsize1(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_initialize_arr(t_arr *arr)
{
	arr->k = 0;
	arr->i = 0;
	arr->j = 0;
	arr->newlist = export;
	arr->n = ft_lstsize1(arr->newlist);
}

char	**array_export(void)
{
	char	**array;
	t_arr	arr;

	ft_initialize_arr(&arr);
	array = (char **)malloc(sizeof(char *) * (arr.n + 1));
	if (array == 0)
		return (NULL);
	while (arr.newlist && arr.j < arr.n)
	{
		arr.k = ft_len((arr.newlist)->content);
		array[arr.j] = malloc(sizeof(char) * (arr.k + 1));
		arr.s = (arr.newlist)->content;
		while (arr.i < arr.k)
		{
			array[arr.j][arr.i] = (arr.s)[arr.i];
			arr.i++;
		}
		array[arr.j][arr.i] = '\0';
		arr.i = 0;
		arr.j++;
		arr.newlist = (arr.newlist)->next;
	}
	array[arr.j] = NULL;
	return (array);
}
