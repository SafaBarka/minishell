/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbarka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:53:37 by sbarka            #+#    #+#             */
/*   Updated: 2021/06/17 18:31:59 by sbarka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_parse_line(char *line)
{
	int		len;
	char	*mask;
	char	*newmask;
	char	*newline;

	len = ft_strlen(line);
	mask = ft_create_mask(line, len);
	newline = ft_strtrim(line, mask, "S");
	newmask = ft_strtrim(mask, mask, "S");
	len = ft_strlen(newmask);
	free(mask);
	free(line);
	if (!newline || !newmask)
		return (-1);
	if (ft_check_errors(newmask, len) != 1)
		return (-1);
	if (!ft_store(&(sh.list), newline, newmask))
		return (-1);
	if (ft_exec(&sh.list) != 1)
		return (127);
	ft_free_list();
	free(newmask);
	free(newline);
	sh.list = NULL;
	return (1);
}
