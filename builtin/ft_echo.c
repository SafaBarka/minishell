/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 21:14:28 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 21:41:41 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	ft_found_singlen(char *arg,	int len)
{
	int	i;

	i = 1;
	if (arg[0] != '-')
		return (-1);
	if (i < len)
	{
		while (arg[i])
		{
			if (arg[i] != 'n')
				return (-1);
			i++;
		}
	}
	return (1);
}

void	ft_check_dash(char **args, int *j, int *found)
{
	while (args[*j])
	{
		if (args[*j][0] == '-' && args[*j][1] == '\0')
		{
			ft_write("-");
			ft_write(" ");
			(*j)++;
			break ;
		}
		else if (ft_found_singlen(args[*j], ft_strlen(args[*j])) == -1)
			break ;
		else
			*found = 1;
		(*j)++;
	}
}

void	ft_write_args(char **args, t_split *current, int *f, int *j)
{
	while (args[*j])
	{
		if (ft_check_dollar(*j, current) == 1)
			args[*j] = ft_strtrim(args[*j], args[*j], " ");
		if (*f == 1 && (args[*j][0] != '\0' || (args[*j][0] == '\0'
			&& ft_check_dollar(*j, current) != 1)))
			ft_write(" ");
		else if (args[*j][0] != '\0' || (args[*j][0] == '\0'
				&& ft_check_dollar(*j, current) != 1))
			*f = 1;
		ft_write(args[*j]);
		(*j)++;
	}
}

int	ft_echo(char **args, char **masks, int i, t_split *current)
{
	int	j;
	int	found;
	int	f;

	j = 1;
	found = -2;
	f = 0;
	ft_check_dash(args, &j, &found);
	ft_write_args(args, current, &f, &j);
	if (found != 1)
		ft_write("\n");
	ret = 0;
	replace_ret(export);
	return (0);
}
