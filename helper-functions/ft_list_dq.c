#include "../header.h"
void ft_store_dq(int i)
{
	 if (!v->p_dq)
        v->p_dq = ft_lstnew_dq(i);
    else
        ft_lstadd_back_dq(&v->p_dq,ft_lstnew_dq(i));
}

t_dq	*ft_lstlast_dq(t_dq *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}


void	ft_lstadd_back_dq(t_dq **alst, t_dq *new)
{
	t_dq *lst;

	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast_dq(*alst);
		lst->next = new;
	}
}

t_dq	*ft_lstnew_dq(int i)
{
	t_dq *element;

	if (!(element = (t_dq *)malloc(sizeof(t_dq))))
		return (NULL);
	element->i = i;
	element->next = NULL;
	return (element);
}


void ft_print_dq()
{
	t_dq *current;
	current = v->p_dq;
	while(current){
		printf("i = %d\n",current->i);
		current = current->next;
	}
}