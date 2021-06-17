#include "../header.h"

t_list	*ft_lstnews(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_backs(t_list **alst, t_list *new)
{
	t_list	*p;

	if (alst == NULL || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		p = *alst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	ft_deletelstsize(t_list *lst)
{
	t_list	*curr;

	curr = lst->next;
	while (curr->next != NULL)
	{
		lst = curr;
		curr = curr->next;
	}
	free(lst->next);
	lst->next = NULL;
}

void	ft_add_list_envp(char **envp)
{
	char	*free_tmp;

	while (*envp)
	{
		ft_lstadd_backs(&export, ft_lstnews(ft_strdup(*envp)));
		envp++;
	}
	free_tmp = ft_strdup("?=0");
	ft_lstadd_backs(&export, ft_lstnews(free_tmp));
}

int	ft_pos(const char *s, int c)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = (char *)s;
	i = 0;
	k = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		if (s[i] == (char)c)
		{
			k = i;
			break ;
		}	
		i++;
	}
	return (k);
}
