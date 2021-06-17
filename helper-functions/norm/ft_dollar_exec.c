/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollar_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:10:59 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 21:04:00 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_find_name(t_dollar *d, char **command, int i)
{
	d->name = ft_s_exec(*command, i + 1, (d->stop - 1) - (i + 1) + 1);
	d->value = ft_value(d->name);
	free(d->name);
	d->maskvalue = ft_strdup(d->value);
	return (1);
}

int	ft_join_command(t_dollar *d, char **mask, char **command, int i)
{
	char	*tmp1;
	char	*tmp2;

	d->tempc = *command;
	d->tempm = *mask;
	tmp1 = ft_substr(d->tempc, 0, i);
	*command = ft_strjoin(tmp1, d->value);
	free(tmp1);
	tmp1 = *command;
	tmp2 = ft_substr(d->tempc, d->stop, (d->len - 1) - d->stop + 1);
	*command = ft_strjoin(*command, tmp2);
	free(tmp1);
	free(tmp2);
	return (1);
}

int	ft_join_mask(t_dollar *d, char **mask, int i)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_substr(d->tempm, 0, i);
	*mask = ft_strjoin(tmp1, d->maskvalue);
	free(tmp1);
	free(d->maskvalue);
	tmp1 = *mask;
	tmp2 = ft_substr(d->tempm, d->stop, (d->len - 1) - d->stop + 1);
	*mask = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
	return (1);
}

void	ft_find_mask(t_dollar *d)
{
	int	j;

	j = 0;
	while (d->maskvalue[j])
	{
		if (d->maskvalue[j] == ' ' && d->inside != 1)
			d->maskvalue[j] = 'S';
		else
			d->maskvalue[j] = 'P';
		j++;
	}
}

void	ft_replace_dollar_exec(char **command, char **mask)
{
	t_dollar	d;
	int			i;

	d.inside = 0;
	i = ft_contain_dollar(*mask);
	while (i != -1)
	{
		if ((*mask)[i] == 'D')
			d.inside = 1;
		d.len = ft_strlen(*mask);
		d.stop = i + 1;
		while ((*mask)[d.stop] == 'v')
			d.stop++;
		ft_find_name(&d, command, i);
		ft_join_command(&d, mask, command, i);
		ft_find_mask(&d);
		ft_join_mask(&d, mask, i);
		free(d.tempm);
		free(d.tempc);
		d.inside = 0;
		i = ft_contain_dollar(*mask);
	}
}
