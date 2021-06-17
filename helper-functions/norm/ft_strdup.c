/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:47:22 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/15 11:48:30 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = ft_strlen(s1);
	i = 0;
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[i] = (s1)[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
