#include "../header.h"

void	check_add_pwd_old(char *buf, char *path)
{
	char	*s;
	int		k;
	int		i;
	t_list	*head;

	k = 1;
	i = 1;
	head = export;
	while (head)
	{
		s = ft_s(head->content, 0, ft_pos(head->content, '='));
		if (!ft_strcmp(s, "PWD"))
			k = 0;
		if (!ft_strcmp(s, "OLDPWD"))
			i = 0;
		head = head->next;
		free(s);
	}
	if (k == 1)
		ft_lstadd_backs(&export, ft_lstnews(ft_strjoin("PWD=",
					getcwd(buf, 4096))));
	if (i == 1)
		ft_lstadd_backs(&export, ft_lstnews(ft_strjoin("OLDPWD=", path)));
}

void	ft_change_path(char *buf, char *path)
{
	t_list	*head;
	char	*s;
	char	*tmp;

	check_add_pwd_old(buf, path);
	head = export;
	while (head)
	{
		s = ft_s(head->content, 0, ft_pos(head->content, '='));
		if (ft_strcmp(s, "PWD") == 0)
		{
			getcwd(buf, 4096);
			tmp = head->content;
			head->content = ft_strjoin("PWD=", buf);
			free(tmp);
		}
		else if (ft_strcmp(s, "OLDPWD") == 0)
		{
			tmp = head->content;
			head->content = ft_strjoin("OLDPWD=", path);
			free(tmp);
		}
		head = head->next;
		free(s);
	}
}

void	ft_more_cw(char **p, char *path, char *buf)
{
	if (chdir(p[1]) == 0)
		ft_change_path(buf, path);
	else
	{
		ft_str_error("minishell: cd: ");
		ft_str_error(p[1]);
		ft_str_error(" : No such file or directory\n");
		ret = 1;
	}
}

void	ft_search_cd(char *path, char *buf)
{
	t_list	*head;
	char	*s;
	char	*home;

	head = export;
	while (head)
	{
		s = ft_s(head->content, 0, ft_pos(head->content, '='));
		if (!ft_strcmp(s, "HOME"))
		{
			home = ft_s(head->content, 5, ft_strlen(head->content) - 4);
			chdir(home);
			ft_change_path(buf, path);
			free(home);
			free(s);
			break ;
		}
		head = head->next;
		free(s);
	}
}

void	ft_cd(int cw, char **p)
{
	char	path[4096];
	char	buf[4096];

	ret = 0;
	getcwd(path, 4096);
	if (cw == 1)
	{
		ft_search_cd(path, buf);
		if (!ft_search_home())
			ft_str_error("minishell: cd: HOME not set\n");
	}
	else
		ft_more_cw(p, path, buf);
	replace_ret(export);
}
