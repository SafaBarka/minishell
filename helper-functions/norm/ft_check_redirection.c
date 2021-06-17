/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:15:57 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/14 13:15:59 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_check_redirection(char *mask)
{
	int	i;

	i = 0;
	while (mask[i])
	{
		if (mask[i] == '>' || mask[i] == '<')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_nbr_redirections(char *mask, int len)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (mask[i])
	{
		if (mask[i] == '<')
			nbr++;
		else if (mask[i] == '>')
		{
			if (i + 1 < len && mask[i + 1] == '>')
				i++;
			nbr++;
		}
		i++;
	}
	return (nbr);
}

int	ft_contain_redirection(char *mask)
{
	int	i;

	i = 0;
	while (mask[i])
	{
		if (mask[i] == '>' || mask[i] == '<')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_end_indice(char *mask, int start, int len)
{
	int	end;

	end = start;
	while (end < len && mask[end] == 'S')
		end++;
	while (end < len && mask[end] != '<' && mask[end] != '>'
		&& mask[end] != 'S')
		end++;
	return (end - 1);
}
