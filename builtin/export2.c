#include "../header.h"

void	ft_sort_alpha(void)
{
	char	*tmp;
	t_list	*i;
	t_list	*j;
	char	*si;
	char	*sj;

	i = export;
	while (i)
	{
		j = i->next;
		while (j)
		{
			si = i->content;
			sj = j->content;
			if (ft_strcmp(i->content, j->content) > 0)
			{
				tmp = i->content;
				i->content = j->content;
				j->content = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	ft_print_declare(void *s, char c)
{
	ft_putstr("declare -x ");
	ft_putstr(s);
	write(1, &c, 1);
}

void	ft_env_part(char *s, char *free_tmp)
{
	ft_putstr(s + 1);
	ft_putstr("\"\n");
	free(free_tmp);
}

void	ft_printlist_env(void)
{
	char	*s;
	char	*free_tmp;
	t_list	*node;

	ft_sort_alpha();
	node = export;
	while (node)
	{
		free_tmp = ft_s(node->content, 0, ft_pos(node->content, '=') + 1);
		if (ft_strcmp(free_tmp, "?=") == 0 || ft_strcmp(free_tmp, "_=") == 0)
			node = node->next;
		free(free_tmp);
		if ((ft_strchr(node->content, '=')) != 0)
		{
			free_tmp = ft_s(node->content, 0, ft_pos(node->content, '=') + 1);
			ft_print_declare(free_tmp, '\"');
			s = ft_strchr(node->content, '=');
			ft_env_part(s, free_tmp);
		}
		else
			ft_print_declare(node->content, '\n');
		node = node->next;
	}
	ret = 0;
	replace_ret(export);
}
