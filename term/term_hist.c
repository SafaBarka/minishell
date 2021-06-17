#include "../header.h"

t_sdlist	*ft_lstlast2(t_sdlist *lst)
{
	if (!lst)
		lst = (void *)0;
	else
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front(t_sdlist **alst, t_sdlist *new)
{
	if (!new)
		new->next = NULL;
	new->next = *alst;
	*alst = new;
}

int	ft_lstsize(t_sdlist *lst)
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_sdlist	*ft_lstnew2(void *line)
{
	t_sdlist	*lst;

	lst = malloc(sizeof(t_sdlist));
	if (!lst)
		return (NULL);
	lst->line = line;
	lst->next = NULL;
	return (lst);
}

void	ft_insertafter(t_sdlist *prev_node, char *new_data)
{
	t_sdlist	*new_node;

	new_node = (t_sdlist *)malloc(sizeof(t_sdlist));
	new_node->line = ft_strdup(new_data);
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;
	new_node->next->prev = new_node;
}
