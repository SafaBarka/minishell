
#include "../header.h"

void ft_store_dollar(int i)
{
	 if (!v->p_dollar)
        v->p_dollar = ft_lstnew_dollar(i);
    else
        ft_lstadd_back_dollar(&v->p_dollar,ft_lstnew_dollar(i));
}

t_dollar	*ft_lstlast_dollar(t_dollar *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}


void	ft_lstadd_back_dollar(t_dollar **alst, t_dollar *new)
{
	t_dollar *lst;

	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast_dollar(*alst);
		lst->next = new;
	}
}

t_dollar	*ft_lstnew_dollar(int i)
{
	t_dollar *element;

	if (!(element = (t_dollar *)malloc(sizeof(t_dollar))))
		return (NULL);
	element->i = i;
	element->next = NULL;
	return (element);
}

void ft_print_dollar()
{
	t_dollar *current;
	current = v->p_dollar;
	while(current){
		printf("i = %d\n",current->i);
		current = current->next;
	}
}