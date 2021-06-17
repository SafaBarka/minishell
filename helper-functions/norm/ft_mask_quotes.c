/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:40:17 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/08 15:40:19 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_start_dq(t_fill_mask *fill, char *line, char *mask, int *i)
{
	mask[*i] = '\"';
	if ((*i) - 1 >= 0 && line[(*i) - 1] == 36)
	{
		mask[(*i) - 1] = '$';
		fill->dollar = 1;
	}
	fill->dq = *i;
}

void	ft_close_dq(t_fill_mask *fill, char *mask, int *i)
{
	mask[*i] = '\"';
	fill->dollar = 0;
	fill->dq = -1;
}

void	ft_start_sq(t_fill_mask *fill, char *line, char *mask, int *i)
{
	mask[*i] = '\'';
	if ((*i) - 1 >= 0 && line[(*i) - 1] == 36)
	{
		mask[(*i) - 1] = '$';
		fill->dollar = 1;
	}
	fill->sq = *i;
}

void	ft_close_sq(t_fill_mask *fill, char *mask, int *i)
{
	mask[*i] = '\'';
	fill->dollar = 0;
	fill->sq = -1;
}
