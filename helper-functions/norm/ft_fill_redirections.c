/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:08:01 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 11:10:21 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_initialize_redirections(t_redir *infos, t_split *pipe,
		t_redirect **redirect)
{
	infos->len = ft_strlen(pipe->mask);
	infos->nbr = ft_nbr_redirections(pipe->mask, infos->len);
	infos->s = 0;
	pipe->nbr_re = infos->nbr;
	*redirect = malloc(sizeof(t_redirect) * (infos->nbr + 1));
	if (!(*redirect))
		return (-1);
	(*redirect)[infos->nbr].file = NULL;
	(*redirect)[infos->nbr].type = NULL;
	return (1);
}

void	ft_out(t_split *pipe, t_redir *infos, int i, t_redirect *redirect)
{
	infos->end = ft_end_indice(pipe->mask, i + 1, infos->len);
	redirect[infos->s].type = ft_strdup("out");
	infos->file = ft_substr(pipe->str, i + 1, (infos->end - (i + 1) + 1));
	redirect[infos->s].file = ft_strtrim(infos->file, infos->file, " ");
	infos->mask = ft_substr(pipe->mask, i + 1, (infos->end - (i + 1) + 1));
	redirect[infos->s].mask = ft_strtrim(infos->mask, infos->mask, "S");
	free(infos->mask);
	free(infos->file);
	(infos->s)++;
}

void	ft_in(t_split *pipe, t_redir *infos, int i, t_redirect *redirect)
{
	infos->end = ft_end_indice(pipe->mask, i + 1, infos->len);
	redirect[infos->s].type = ft_strdup("in");
	infos->file = ft_substr(pipe->str, i + 1, (infos->end - (i + 1) + 1));
	redirect[infos->s].file = ft_strtrim(infos->file, infos->file, " ");
	infos->mask = ft_substr(pipe->mask, i + 1, (infos->end - (i + 1) + 1));
	redirect[infos->s].mask = ft_strtrim(infos->mask, infos->mask, "S");
	free(infos->mask);
	free(infos->file);
	(infos->s)++;
}

void	ft_append(t_split *pipe, t_redir *infos, int i, t_redirect *redirect)
{
	infos->end = ft_end_indice(pipe->mask, i + 2, infos->len);
	redirect[infos->s].type = ft_strdup("append");
	infos->file = ft_substr(pipe->str, i + 2, (infos->end - (i + 2) + 1 ));
	redirect[infos->s].file = ft_strtrim(infos->file, infos->file, " ");
	infos->mask = ft_substr(pipe->mask, i + 2, (infos->end - (i + 2) + 1));
	redirect[infos->s].mask = ft_strtrim(infos->mask, infos->mask, "S");
	free(infos->mask);
	free(infos->file);
	(infos->s)++;
}
