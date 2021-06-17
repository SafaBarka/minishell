/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_mask.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:39:30 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/08 15:39:40 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_no_quotes(char *line, char *mask, int len, int *i)
{
	if (line[*i] == 92 && (*i) + 1 < len)
	{
		mask[*i] = '\\';
		mask[(*i) + 1] = 'P';
		(*i)++;
	}
	else if (line[*i] != 92)
	{
		if (line[*i] == ';')
			mask[*i] = ';';
		else if (line[*i] == '$')
			mask[*i] = 'O';
		else if (line[*i] == ' ')
			mask[*i] = 'S';
		else if (line[*i] == '|')
			mask[*i] = '|';
		else if (line[*i] == '#')
			mask[*i] = '#';
		else if (line[*i] == '(' || line[*i] == ')')
			mask[*i] = line[*i];
		else if (line[*i] == '>' || line[*i] == '<')
			mask[*i] = line[*i];
		else
			mask[*i] = 'P';
	}
}

void	ft_inside_dq(char *line, char *mask, int len, int *i)
{
	if (line[*i] == 92 && (*i) + 1 < len)
	{
		mask[(*i) + 1] = 'P';
		if (line[(*i) + 1] == 36)
			mask[*i] = '\\';
		else if (line[(*i) + 1] == 92)
			mask[*i] = '\\';
		else if (line[(*i) + 1] == 34)
			mask[*i] = '\\';
		else
			mask[*i] = 'P';
		(*i)++;
	}
	else if (line[*i] != 92)
	{
		if (line[*i] == '$')
			mask[*i] = 'D';
		else
			mask[*i] = 'P';
	}
}

void	ft_inside_sq_dollar(char *line, char *mask, int len, int *i)
{
	if (line[*i] == 92 && (*i) + 1 < len)
	{
		if (line[(*i) + 1] == 92)
			mask[*i] = '\\';
		else if (line[(*i) + 1] == 36)
			mask[*i] = 'P';
		else if (line[(*i) + 1] == 39)
			mask[*i] = '\\';
		else if (line[(*i) + 1] == 34)
			mask[*i] = '\\';
		else
			mask[*i] = 'P';
		mask[(*i) + 1] = 'P';
		if (line[(*i) + 1] == 34 || line[(*i) + 1] == 39
			|| line[(*i) + 1] == 36 || line[(*i) + 1] == 92
			|| line[(*i) + 1] == ';')
			(*i)++;
	}
	else if (line[*i] != 92)
		mask[*i] = 'P';
}

void	ft_inside_sq(char *line, char *mask, int len, int *i)
{
	if (line[*i] == 92 && (*i) + 1 < len)
	{
		mask[*i] = 'P';
		mask[(*i) + 1] = 'P';
		if (line[(*i) + 1] == 92 || line[(*i) + 1] == 36 || line[(*i) + 1] == 34
			|| line[(*i) + 1] == ';')
			(*i)++;
	}
	else if (line[*i] != 92)
		mask[*i] = 'P';
}

void	ft_fill_mask(t_fill_mask *fill, char *line, char *mask, int *i)
{
	if (line[*i] == 34 && fill->dq == -1 && fill->sq == -1)
		ft_start_dq(fill, line, mask, i);
	else if (line[*i] == 34 && fill->dq != -1)
		ft_close_dq(fill, mask, i);
	else if (line[*i] == 39 && fill->sq == -1 && fill->dq == -1)
		ft_start_sq(fill, line, mask, i);
	else if (line[*i] == 39 && fill->sq != -1)
		ft_close_sq(fill, mask, i);
	else if (fill->sq != -1 && fill->dollar == 0)
		ft_inside_sq(line, mask, fill->len, i);
	else if (fill->sq != -1 && fill->dollar == 1)
		ft_inside_sq_dollar(line, mask, fill->len, i);
	else if (fill->dq != -1)
		ft_inside_dq(line, mask, fill->len, i);
	else if (fill->dq == -1 && fill->sq == -1)
		ft_no_quotes(line, mask, fill->len, i);
}
