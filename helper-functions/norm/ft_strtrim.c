/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:57:24 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/15 11:57:27 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	ft_start(char *s, char *set, int l)
{
	int	j;
	int	c;

	j = 0;
	c = 0;
	if (set[0] == '\0')
		return (0);
	while (s[c] != '\0')
	{
		j = 0;
		while (j < l)
		{
			if (s[c] != set[j] && j == l - 1)
				return (c);
			else if (s[c] != set[j])
				j++;
			else
				break ;
		}
		c++;
	}
	return (c);
}

static int	ft_end(char *s, char *set, int l, int r)
{
	int	c;
	int	j;

	c = l - 1;
	j = 0;
	if (set[0] == '\0')
		return (ft_strlen(s) - 1);
	while (c >= 0)
	{
		j = 0;
		while (j < r)
		{
			if (s[c] != set[j] && j == r - 1)
				return (c);
			else if (s[c] != set[j])
				j++;
			else
				break ;
		}
		c--;
	}
	return (c);
}

static char	*ft_allocation(char *str)
{
	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char *s1, char *s2, char *set)
{
	int		j;
	int		i;
	t_trim	t;

	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	t.start = ft_start((char *)s2, (char *)set, ft_strlen(set));
	t.end = ft_end((char *)s2, (char *)set, ft_strlen(s2), ft_strlen(set));
	i = t.start;
	t.str = NULL;
	if (t.end < 0)
		return (ft_allocation(t.str));
	t.str = (char *)malloc(sizeof(char) * (t.end - t.start + 2));
	if (!t.str)
		return (NULL);
	while (i <= t.end)
	{
		t.str[j] = s1[i];
		j++;
		i++;
	}
	t.str[j] = '\0';
	return (t.str);
}
