#include "../header.h"

void	ft_error_exit(char **p)
{
	ft_str_error("exit\nminishell: exit: ");
	ft_str_error(p[1]);
	ft_str_error(": numeric argument required\n");
	exit(255);
}

void	ft_error1_exit(void)
{
	ft_str_error("exit\nminishell: exit: too many arguments\n");
	ret = 1;
	replace_ret(export);
}

void	ft_more_word(char **p, int j, int k)
{
	j = 1;
	if (p[1][0] == ' ' || p[1][0] == '+')
	{
		while (p[1][j])
		{
			if (ft_isdigit(p[1][j]))
				k++;
			j++;
		}
		if (k + 1 == ft_strlen(p[1]))
			exit(ft_atoi(p[1]));
	}	
	else if (!ft_isdigit(p[1][0]) && p[1][0] != ' ')
		ft_error_exit(p);
	else if (p[1][0] != ' ')
	{
		if (ft_isdigit(p[1][0]))
			ft_error1_exit();
	}
}

void	ft_exit(int cw, char **p)
{
	int	k;
	int	j;

	ret = 0;
	k = 0;
	j = 0;
	if (cw == 1)
		exit(ret);
	if (cw == 2 && (ft_isdigit(p[1][0]) || p[1][0] == '-'))
	{
		while (p[1][j])
		{
			if (ft_isdigit(p[1][j]))
				k++;
			j++;
		}
		if (k != 0)
			exit(ft_atoi(p[1]));
		else
			exit(ft_atoi(p[1]));
	}
	else if (cw >= 2)
		ft_more_word(p, j, k);
}
