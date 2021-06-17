/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:02:02 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/15 12:06:08 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_n(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*src;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	src = (char *)malloc(len + 1);
	if (src == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		src[i] = s[start];
		i++;
		start++;
	}
	src[i] = '\0';
	return (src);
}

char	*ft_value(char *s)
{
	t_list	*node;
	char	*s1;
	char	*tmp;

	node = export;
	while (node)
	{
		s1 = ft_n(node->content, 0, ft_pos(node->content, '='));
		if (ft_strcmp(s, s1) == 0)
		{
			s = ft_strchr(node->content, '=');
			free(s1);
			return (s + 1);
		}
		free(s1);
		node = node->next;
	}
	tmp = "";
	return (tmp);
}
