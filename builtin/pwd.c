#include "../header.h"

void	replace_ret(t_list *node)
{
	char	*s1;
	char	*s;
	char	*a;
	char	*free_tmp;

	while (node)
	{
		s1 = ft_s(node->content, 0, ft_pos(node->content, '=') + 1);
		s = ft_strchr(node->content, '=');
		if (ft_strcmp(s1, "?=") == 0)
		{
			free_tmp = ft_itoa(ret);
			a = ft_strjoin("?=", free_tmp);
			free(free_tmp);
			free_tmp = node->content;
			node->content = ft_strdup(a);
			free(a);
			free(free_tmp);
			free(s1);
			break ;
		}
		node = node->next;
		free(s1);
	}
}

void	ft_pwd(int cw)
{
	char	buf[4096];

	ret = 0;
	if (cw == 1)
	{
		getcwd(buf, 4096);
		ft_putstr(buf);
		ft_putstr("\n");
		ret = 0;
	}
	else
	{
		ft_str_error("pwd: too many arguments");
		ft_str_error("\n");
		ret = 0;
	}
	replace_ret(export);
}
