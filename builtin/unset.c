#include "../header.h"

void	ft_del_pos(t_list **head, int pos)
{
	t_list	*curr;
	t_list	*prev;

	curr = *head;
	prev = *head;
	if (pos == 1)
	{
		*head = curr->next;
		free(curr);
		curr = NULL;
	}
	else
	{
		while (pos != 1)
		{
			prev = curr;
			curr = curr->next;
			pos--;
		}
		prev->next = curr->next;
		free(curr);
		curr = NULL;
	}
}

void	ft_find_pos(char **p, int i)
{
	t_list	*head;
	char	*s;
	int		j;

	head = export;
	j = 1;
	while (head)
	{
		s = ft_s(head->content, 0, ft_pos(head->content, '='));
		if (!ft_strcmp(p[i], s) || (!ft_strcmp(p[i], head->content)
				&& !ft_strchr(p[i], '=')))
		{
			ft_del_pos(&export, j);
			ret = 0;
			free(s);
			break ;
		}
		free(s);
		head = head->next;
		j++;
	}
}

void	ft_unset(char **p, int cw)
{
	int		i;

	i = 1;
	if (cw > 1)
	{
		while (p[i])
		{
			ft_find_pos(p, i);
			if (ft_check_cp(p[i]))
			{
				ft_str_error("minishell: unset: `");
				ft_str_error(p[i]);
				ft_str_error("': not a valid identifier\n");
				ret = 1;
			}
			i++;
		}
	}
	replace_ret(export);
}
