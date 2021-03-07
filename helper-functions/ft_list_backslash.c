#include "../header.h"

void ft_store_backslash(int i)
{
	 if (!v->p_backslash)
        v->p_backslash = ft_lstnew_backslash(i);
    else
        ft_lstadd_back_backslash(&v->p_backslash,ft_lstnew_backslash(i));
}

t_backslash	*ft_lstlast_backslash(t_backslash *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}


void	ft_lstadd_back_backslash(t_backslash **alst, t_backslash *new)
{
	t_backslash *lst;

	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast_backslash(*alst);
		lst->next = new;
	}
}

t_backslash	*ft_lstnew_backslash(int i)
{
	t_backslash *element;

	if (!(element = (t_backslash *)malloc(sizeof(t_backslash))))
		return (NULL);
	element->i = i;
	element->next = NULL;
	return (element);
}

void ft_print_backslash()
{
	t_backslash *current;
	current = v->p_backslash;
	while(current){
		printf("i = %d\n",current->i);
		current = current->next;
	}
}