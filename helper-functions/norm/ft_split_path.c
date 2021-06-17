/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:51:57 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 12:15:33 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static char	**free_tab(int i, char **str)
{
	while (--i >= 0)
	{
		free(str[i]);
	}
	free(str);
	return (NULL);
}

static char	**result(int i, int cw, char **str)
{
	if (i == cw)
		str[i] = NULL;
	return (str);
}

int	ft_count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == NULL || !s[i])
		return (0);
	while (s[i] == c)
		i++;
	if (s[i])
	{
		count++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

void	ft_sub_path(t_sub_path *split, char *mask, char c)
{
	while (((char *)mask)[split->end] && ((char *)mask)[split->end] == c)
		split->end++;
	split->start = split->end;
	split->end++;
	while (((char *)mask)[split->end] && ((char *)mask)[split->end] != c)
		split->end++;
}

char	**ft_split_path(char *s, char *mask, char c)
{
	t_sub_path	split;
	char		**str;

	split.start = 0;
	split.end = 0;
	split.i = 0;
	split.cw = ft_count_words((char *)mask, c);
	str = (char **)malloc(sizeof(char *) * (split.cw + 1));
	if (mask == NULL || !str)
		return (NULL);
	while (((char *)mask)[split.end] && split.i != split.cw)
	{
		ft_sub_path(&split, mask, c);
		if (split.i < split.cw)
		{
			str[split.i++] = ft_substr(s, split.start,
					(split.end - 1) - split.start + 1);
			if (!str[split.i - 1])
				return (free_tab(split.i, str));
		}
	}
	return (result(split.i, split.cw, str));
}
