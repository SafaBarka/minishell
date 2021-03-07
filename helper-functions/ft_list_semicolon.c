#include "../header.h"

void ft_store_semicolon( int i)
{
	 if (!v->p_semicolon)
        v->p_semicolon = ft_lstnew_semicolon(i);
    else
        ft_lstadd_back_semicolon(&v->p_semicolon,ft_lstnew_semicolon(i));
}

t_semicolon	*ft_lstlast_semicolon(t_semicolon *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}


void	ft_lstadd_back_semicolon(t_semicolon **alst, t_semicolon *new)
{
	t_semicolon *lst;

	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast_semicolon(*alst);
		lst->next = new;
	}
}

t_semicolon	*ft_lstnew_semicolon(int i)
{
	t_semicolon *element;

	if (!(element = (t_semicolon *)malloc(sizeof(t_semicolon))))
		return (NULL);
	element->i = i;
	element->next = NULL;
	return (element);
}


void ft_print_semicolon()
{
	t_semicolon *current;
	current = v->p_semicolon;
	while(current){
		printf("i = %d\n",current->i);
		current = current->next;
	}
}