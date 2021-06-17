/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:49:46 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/14 20:56:20 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_fill_arg(t_args *f, char ***args, char ***masks, int *i)
{
	while (*i < f->nbrargs)
	{
		f->newargs[*i] = (*args)[*i];
		f->newmask[*i] = (*masks)[*i];
		(*i)++;
	}
	free(*args);
	free(*masks);
}

void	ft_fill_args_last(t_args *f, char ***args, char ***masks, int *i)
{
	int	j;

	if (f->tmps[0] == NULL && f->str[0] == '\0')
	{
		f->newargs[*i] = ft_strdup("");
		f->newmask[*i] = ft_strdup("--");
		i++;
	}
	else
	{
		j = 0;
		while (j < f->nbrsplit)
		{
			f->newargs[*i] = f->tmps[j];
			f->newmask[*i] = f->tmpm[j];
			(*i)++;
			j++;
		}
	}
	free(f->tmps);
	free(f->tmpm);
}

int	ft_initialize_fill_args(t_args *f, char ***args, char ***masks)
{
	f->nbrargs = ft_nbr_args(*args);
	f->nbrsplit = ft_count_words(f->mask, 'S');
	if (f->nbrsplit == 0 && f->str[0] == '\0')
		f->nbrsplit++;
	f->total = f->nbrargs + f->nbrsplit;
	f->newargs = malloc(sizeof(char *) * (f->total + 1));
	f->newmask = malloc(sizeof(char *) * (f->total + 1));
	f->newargs[f->total] = NULL;
	f->newmask[f->total] = NULL;
	f->tmps = ft_split_path(f->str, f->mask, 'S');
	f->tmpm = ft_split_path(f->mask, f->mask, 'S');
	return (1);
}

void	ft_fill(char ***args, char ***masks, char *str, char *mask)
{
	t_args	f;
	int		i;

	f.str = str;
	f.mask = mask;
	ft_initialize_fill_args(&f, args, masks);
	i = 0;
	ft_fill_arg(&f, args, masks, &i);
	ft_fill_args_last(&f, args, masks, &i);
	*args = f.newargs;
	*masks = f.newmask;
}
