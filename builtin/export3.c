#include "../header.h"

void	ft_free(char *s1, char *s2, char *s3)
{
	free(s1);
	free(s2);
	free(s3);
}

void	ft_free_path(char *s1, char *s2, char *s3)
{
	ft_free_double(sh.path);
	sh.path = ft_path();
	ft_free(s1, s2, s3);
}

int	ft_find_env(t_list	*new, char *s)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*tmp;

	while (new)
	{
		s1 = ft_s(new->content, 0, ft_pos(new->content, '=') + 1);
		s2 = ft_s(new->content, 0, ft_pos(new->content, '='));
		s3 = ft_s(s, 0, ft_pos(s, '='));
		if (ft_strcmp(s, new->content) == 0 || ft_strcmp(s, s2) == 0)
		{
			ft_free(s1, s2, s3);
			return (1);
		}
		else if (ft_strcmp(s, s1) == 0 || (ft_strchr(s, '=')
				&& (ft_strcmp(s3, new->content) == 0
					|| (ft_strcmp(s3, s2) == 0))))
		{
			tmp = new->content;
			new->content = ft_strdup(s);
			free(tmp);
			ft_free_path(s1, s2, s3);
			return (1);
		}
		ft_free(s1, s2, s3);
		new = new->next;
	}
	return (0);
}

int	ft_f(char *s)
{
	int		i;
	t_list	*new;

	i = 0;
	new = export;
	while (s[i])
	{
		if (ft_find_env(new, s))
			return (1);
		i++;
	}
	return (0);
}
