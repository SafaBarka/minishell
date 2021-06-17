/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_bq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 20:27:12 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 12:23:33 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_contain_quote(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"' || s[i] == '\\')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_rem_s(char **s, int len, int i)
{
	t_remove_redir	rm;
	char			*tmp1;

	rm.before = ft_substr(*s, 0, i);
	rm.after = ft_substr(*s, i + 1, (len - 1 - (i + 1) + 1));
	rm.join = ft_strjoin(rm.before, rm.after);
	tmp1 = *s;
	*s = rm.join;
	free(tmp1);
	free(rm.before);
	free(rm.after);
}

void	ft_rem_m(char **s, char **m, int len, int i)
{
	t_remove_redir	rm ;
	char			*tmp2;

	rm.before = ft_substr(*m, 0, i);
	rm.after = ft_substr(*m, i + 1, (len - 1 - (i + 1) + 1));
	rm.join = ft_strjoin(rm.before, rm.after);
	tmp2 = *m;
	*m = rm.join;
	free(tmp2);
	free(rm.before);
	free(rm.after);
}

int	ft_remove_bq(char **s, char **m)
{
	int				len;
	int				i;

	len = ft_strlen(*s);
	i = ft_contain_quote(*m);
	while (i != -1)
	{
		ft_rem_s(s, len, i);
		ft_rem_m(s, m, len, i);
		if (!*s || !*m)
			return (-1);
		len = ft_strlen(*s);
		i = ft_contain_quote(*m);
	}
	return (1);
}
