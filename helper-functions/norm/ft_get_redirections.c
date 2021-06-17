/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:24:50 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 12:25:18 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_create_str(t_redir *infos, t_split *pipe, int i)
{
	t_remove_redir	rm_str;

	rm_str.before = ft_substr(pipe->str, 0, i);
	rm_str.after = ft_substr(pipe->str, infos->end + 1,
			(infos->len - 1 - (infos->end + 1) + 1));
	free(pipe->str);
	rm_str.join = ft_strjoin(rm_str.before, rm_str.after);
	pipe->str = rm_str.join;
	if (!pipe->str)
		return (-1);
	free(rm_str.before);
	free(rm_str.after);
	return (1);
}

int	ft_create_m(t_redir *infos, t_split *pipe, int i)
{
	t_remove_redir	rm_mask;

	rm_mask.before = ft_substr(pipe->mask, 0, i);
	rm_mask.after = ft_substr(pipe->mask, infos->end + 1,
			(infos->len - 1 - (infos->end + 1) + 1));
	free(pipe->mask);
	rm_mask.join = ft_strjoin(rm_mask.before, rm_mask.after);
	pipe->mask = rm_mask.join;
	if (!pipe->mask)
		return (-1);
	free(rm_mask.before);
	free(rm_mask.after);
	return (1);
}

int	ft_check(t_redir *infos, t_split *pipe, int i, t_redirect *redirect)
{
	if (pipe->mask[i] == '>' && i + 1 < infos->len && pipe->mask[i + 1] == '>')
		ft_append(pipe, infos, i, redirect);
	else if (pipe->mask[i] == '>')
		ft_out(pipe, infos, i, redirect);
	else if (pipe->mask[i] == '<')
		ft_in(pipe, infos, i, redirect);
	if (ft_create_str(infos, pipe, i) == -1)
		return (-1);
	if (ft_create_m(infos, pipe, i) == -1)
		return (-1);
	return (1);
}

int	ft_get_redirection(t_split *pipe)
{
	t_redir			infos;
	t_remove_redir	rm;
	int				i;
	t_redirect		*redirect;

	if (ft_initialize_redirections(&infos, pipe, &redirect) == -1)
		return (-1);
	i = ft_contain_redirection(pipe->mask);
	while (i != -1)
	{
		ft_check(&infos, pipe, i, redirect);
		rm.before = pipe->str;
		rm.after = pipe->mask;
		pipe->str = ft_strtrim(rm.before, rm.after, "S");
		pipe->mask = ft_strtrim(rm.after, rm.after, "S");
		free(rm.before);
		free(rm.after);
		infos.len = ft_strlen(pipe->mask);
		i = ft_contain_redirection(pipe->mask);
	}
	pipe->redirections = redirect;
	return (1);
}
