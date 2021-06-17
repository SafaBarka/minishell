/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:12:17 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/08 21:12:19 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_error(char *s)
{
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	return (2);
}

void	ft_write(char *s)
{
	write(1, s, ft_strlen(s));
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
