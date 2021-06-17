/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 20:37:35 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 20:47:26 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_contain_dollar(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (s[i])
	{
		if ((s[i] == 'D' || s[i] == 'O') && i + 1 < len && s[i + 1] == 'v')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_r_comamnd(t_dollar_redir *d, char **command, char **mask, int i)
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
	*command = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

void	ft_r_mask(t_dollar_redir *d, char **command, char **mask, int i)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_substr(d->tempm, 0, i);
	*mask = ft_strjoin(tmp1, d->value);
	free(tmp1);
	tmp1 = *mask;
	tmp2 = ft_substr(d->tempm, d->stop, (d->len - 1) - d->stop + 1);
	*mask = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}

void	ft_replace_dollar(char **command, char **mask)
{
	t_dollar_redir	d;
	int				i;

	d.inside = 0;
	d.inside = 0;
	i = ft_contain_dollar(*mask);
	while (i != -1)
	{
		d.len = ft_strlen(*mask);
		d.stop = i + 1;
		while ((*mask)[d.stop] == 'v')
			d.stop++;
		d.name = ft_s(*command, i + 1, (d.stop - 1) - (i + 1) + 1);
		d.value = ft_value(d.name);
		free(d.name);
		ft_r_comamnd(&d, command, mask, i);
		ft_r_mask(&d, command, mask, i);
		i = ft_contain_dollar(*mask);
		free(d.tempc);
		free(d.tempm);
	}
}
