/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 19:03:20 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 12:15:53 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_nbr_words(char *mask, int len, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (mask[0] == '\0')
		return (0);
	count++;
	i++;
	while (i < len)
	{
		if (mask[i] == c && (i + 1) < len && mask[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

void	ft_store_semi(char **s, char **m)
{
	char	*tmps;
	char	*tmpm;

	tmps = *s;
	tmpm = *m;
	*s = ft_strtrim(*s, *m, "S");
	*m = ft_strtrim(*m, *m, "S");
	free(tmpm);
	free(tmps);
}

int	ft_store_elements(t_sub_split *spl, t_store *store, t_split **list)
{
	char	*s;
	char	*m;

	s = ft_substr(store->str, spl->start, (spl->end - 1) - spl->start + 1);
	m = ft_substr(store->mask, spl->start, (spl->end - 1) - spl->start + 1);
	if (!s || !m)
		return (-1);
	if (store->c == 'S')
		ft_remove_bq(&s, &m);
	if (store->c == ';' || store->c == '|')
	{
		ft_store_semi(&s, &m);
		if (!s || !m || !ft_store_list(list, s, m, store))
			return (-1);
	}
	else
		if (!(ft_store_list(list, s, m, store)))
			return (-1);
	spl->i++;
	return (1);
}

int	ft_split(t_split **list, t_store *store)
{
	t_sub_split	spl;

	spl.start = 0;
	spl.end = 0;
	spl.i = 0;
	while (((char *)store->mask)[spl.end] && spl.i != store->count)
	{
		while (((char *)store->mask)[spl.end]
				&& ((char *)store->mask)[spl.end] == store->c)
			spl.end++;
		spl.start = spl.end;
		spl.end++;
		while (((char *)store->mask)[spl.end]
				&& ((char *)store->mask)[spl.end] != store->c)
			spl.end++;
		if (spl.i < store->count)
		{
			if (ft_store_elements(&spl, store, list) == -1)
				return (-1);
		}
	}
	return (1);
}
