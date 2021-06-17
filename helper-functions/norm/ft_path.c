/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:10:59 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/15 12:18:12 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_free_double(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

char	**ft_path(void)
{
	char	**split;
	char	*path;
	int		i;
	t_list	*current;

	path = NULL;
	split = NULL;
	i = 0;
	current = export;
	while (current != NULL)
	{
		if (ft_strncmp("PATH=", current->content, 5) == 0)
		{
			path = current->content + 5;
			break ;
		}
		i++;
		current = current->next;
	}
	if (path[0] != '\0')
		is_f = 1;
	else
		is_f = -1;
	split = ft_split_path(path, path, ':');
	return (split);
}
