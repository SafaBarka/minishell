#include "../header.h"

int	ft_err(char **p, int j)
{
	ft_str_error("minishell: export: `");
	ft_str_error(p[j]);
	ft_str_error("': not a valid identifier\n");
	return (ret = 1);
}

void	ft_dash(char **p, int j)
{
	ft_str_error("export: ");
	ft_str_error(p[j]);
	ft_str_error(": invalid option\n");
	ft_str_error("export: usage: export [-nf]");
	ft_str_error(" [name[=value] ...] or export -p\n");
	ret = 2;
}

int	ft_ex_continue(char **p, int *j)
{
	if (ft_f(p[*j]) == 1 || (p[*j][0] == 95 && ft_strlen(p[*j]) == 1))
	{
		(*j)++;
		return (1);
	}
	return (0);
}

int	ft_check_cp(char *s)
{
	int		i;
	int		j;
	char	*tab;

	tab = "$&|;-+~!@^%{} []:?.#/,\'\\\"";
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (tab[j] != '\0')
		{
			if (s[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
