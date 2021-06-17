#include "../header.h"

int	ft_ex_dash(char **p, int *j)
{
	if (p[*j][0] == 45 && ft_strlen(p[*j]) > 1)
	{
		ft_dash(p, *j);
		return (1);
	}
	return (0);
}

int	ft_ex_caractere_spec(char **p, int *j, char **masks, char *var)
{
	if (p[*j][0] == '\0' || (p[*j][0] == '#' && masks[*j][0] == 'P')
		|| p[*j][0] == '=' || (ft_check_cp(var) && (p[*j][0] != '#'))
		|| ft_isdigit(p[*j][0]))
	{
		return (1);
	}
	return (0);
}

int	ft_hash(char **p, int j, t_split *current, char **masks)
{
	if ((p[j][0] == '#' && masks[j][0] != 'P') || (p[j][0] == '\0'
			&& ft_check_dollar(j, current) == 1))
	{
		ft_sort_alpha();
		ft_printlist_env();
		return (1);
	}
	return (0);
}

int	ft_part_ex(char **p, int j, char **masks, char *var)
{
	t_list	*newlist;

	ret = 0;
	newlist = export;
	if (ft_ex_dash(p, &j))
		return (0);
	else if (ft_ex_caractere_spec(p, &j, masks, var))
	{
		ft_err(p, j);
		return (0);
	}	
	else if (ft_ex_continue(p, &j))
		return (1);
	else
	{
		ft_lstadd_backs(&newlist, ft_lstnews(ft_strdup(p[j])));
		return (0);
	}	
	return (1);
}

void	ft_add_export(char **p, char **masks, int cw, t_split *current)
{
	int		j;
	char	*var;

	ret = 0;
	if (cw == 1)
		ft_printlist_env();
	else if (cw > 1)
	{
		j = 1;
		while (j < cw)
		{
			var = gat_var(p[j], var);
			if (ft_hash(p, j, current, masks) || (ft_part_ex(p, j, masks, var)))
			{
				ft_free_tmp(var, p[j]);
				break ;
			}
			ft_free_tmp(var, p[j]);
			j++;
		}
	}
	replace_ret(export);
}
