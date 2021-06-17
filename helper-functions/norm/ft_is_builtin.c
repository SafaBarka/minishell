/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:21:40 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 18:30:25 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_is_builtin(char *name)
{
	if (ft_strncmp(name, "export", 7) != 0 && ft_strncmp(name, "env", 4) != 0
		&& ft_strncmp(name, "pwd", 4) != 0 && ft_strncmp(name, "cd", 3) != 0
		&& ft_strncmp(name, "unset", 6) != 0 && ft_strncmp(name, "echo", 5) != 0
		&& ft_strncmp(name, "exit", 5) != 0)
		return (0);
	return (1);
}

int	ft_ambiguous(t_redirect *redirect, int i, char *mask)
{
	if ((ft_contain(redirect[i].mask, 'O') != -1
			&& (redirect[i].file)[0] == '\0')
			|| (ft_contain(mask, 'O') != -1
				&& ft_contain(redirect[i].file, ' ') != -1))
		return (1);
	return (0);
}
