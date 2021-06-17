/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:39:50 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/08 15:39:52 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

char	*ft_create_mask(char *line, int len)
{
	t_fill_mask	*fill;
	int			i;
	char		*mask;

	fill = malloc(sizeof(t_fill_mask));
	mask = ft_strdup(line);
	if (!fill || !mask)
		return (NULL);
	fill->dq = -1;
	fill->sq = -1;
	fill->dollar = 0;
	fill->len = len;
	i = 0;
	while (i < len)
	{
		ft_fill_mask(fill, line, mask, &i);
		i++;
		mask = ft_dollar(mask, line, fill->len);
	}
	free(fill);
	return (mask);
}
