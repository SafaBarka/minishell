/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:07:44 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/08 21:09:46 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	str = NULL;
	if (s == NULL)
		return (NULL);
	else if (start >= ft_strlen((char *)s))
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	else
	{
		i = (size_t)start;
		while (i < (len + start))
		{
			str[j] = ((char *)s)[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}
