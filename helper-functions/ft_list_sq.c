#include "../header.h"

void ft_store_sq(int i)
{
	 if (!v->p_sq)
        v->p_sq = ft_lstnew_sq(i);
    else
        ft_lstadd_back_sq(&v->p_sq,ft_lstnew_sq(i));
}

t_sq	*ft_lstlast_sq(t_sq *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}


void	ft_lstadd_back_sq(t_sq **alst, t_sq *new)
{
	t_sq *lst;

	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast_sq(*alst);
		lst->next = new;
	}
}

t_sq	*ft_lstnew_sq(int i)
{
	t_sq *element;

	if (!(element = (t_sq *)malloc(sizeof(t_sq))))
		return (NULL);
	element->i = i;
	element->next = NULL;
	return (element);
}

void ft_print_sq()
{
	t_sq *current;
	current = v->p_sq;
	while(current){
		printf("i = %d\n",current->i);
		current = current->next;
	}
}