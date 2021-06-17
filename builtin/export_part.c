#include "../header.h"

void	ft_free_tmp(char *var, char *p)
{
	if (ft_strchr(p, '='))
		free(var);
}

char	*gat_var(char *p, char *var)
{
	if (ft_strchr(p, '='))
		var = ft_s(p, 0, ft_pos(p, '='));
	else
		var = p;
	return (var);
}