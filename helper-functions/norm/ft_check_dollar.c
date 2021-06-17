/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 11:23:53 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/15 11:26:04 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_check_dollar(int j, t_split *current)
{
	int	i;

	i = 0;
	while (current)
	{
		if (i == j)
		{
			if ((current->mask)[0] == '$')
				return (1);
		}
		i++;
		current = current->next;
	}
	return (-1);
}
