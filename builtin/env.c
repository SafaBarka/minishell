#include "../header.h"

void	ft_print_node(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(STDOUT_FILENO, &s[i], 1);
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

void	ft_more_cw_env(char **p)
{
	ft_str_error("env: ");
	ft_str_error(p[1]);
	ft_str_error(": No such file or directory\n");
	ret = 1;
}

void	ft_return_env(void)
{
	ret = 0;
	replace_ret(export);
}

void	ft_sort_env(int cw, char **p)
{
	t_list	*node;
	char	*s2;

	node = export;
	if (cw == 1)
	{
		while (node)
		{
			s2 = ft_s(node->content, 0, ft_pos(node->content, '=') + 1);
			if (ft_strchr(node->content, '='))
			{
				if (ft_strcmp(s2, "?=") == 0 || ft_strcmp(s2, "_=") == 0)
					node = node->next;
				else
					ft_print_node(node->content);
			}
			node = node->next;
			free(s2);
		}
	}
	else
		ft_more_cw_env(p);
	ft_return_env();
}
