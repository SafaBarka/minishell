#include "../header.h"

t_indice	*ft_lstlast(t_indice *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

t_indice	*ft_lstnew(int i)
{
	t_indice *element;

	if (!(element = (t_indice *)malloc(sizeof(t_indice))))
		return (NULL);
	element->i = i;
	element->next = NULL;
	return (element);
}

void	ft_lstadd_back(t_indice **alst, t_indice *new)
{
	t_indice *lst;
	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
	}
}

void ft_print(t_indice *head)
{
	t_indice *current;
	current = head;
	while(current){
		printf("i = %d\n",current->i);
		current = current->next;
	}
}


void ft_store_backslash(int i)
{
	 if (!v->p_backslash)
        v->p_backslash = ft_lstnew(i);
    else
        ft_lstadd_back(&v->p_backslash,ft_lstnew(i));
}

void ft_store_dollar(int i)
{
	 if (!v->p_dollar)
        v->p_dollar = ft_lstnew(i);
    else
        ft_lstadd_back(&v->p_dollar,ft_lstnew(i));
}

void ft_store_dq(int i)
{
	 if (!v->p_dq)
        v->p_dq = ft_lstnew(i);
    else
        ft_lstadd_back(&v->p_dq,ft_lstnew(i));
}

void ft_store_semicolon( int i)
{
	 if (!v->p_semicolon)
        v->p_semicolon = ft_lstnew(i);
    else
        ft_lstadd_back(&v->p_semicolon,ft_lstnew(i));
}
void ft_store_sq(int i)
{
	 if (!v->p_sq)
        v->p_sq = ft_lstnew(i);
    else
        ft_lstadd_back(&v->p_sq,ft_lstnew(i));
}