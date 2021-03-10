#include "../header.h"

void ft_store_split_semicolon(char *s, char *mask)
{
   
    if(!v->semicolon)
        v->semicolon = ft_lstnew(s, mask);
    else
        ft_lstadd_back(&v->semicolon, ft_lstnew(s, mask));
    
}

t_semicolon	*ft_lstlast(t_semicolon *lst)
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

t_semicolon	*ft_lstnew(char *split_semicolon, char *mask_semicolon)
{
	t_semicolon *element;

	if (!(element = (t_semicolon *)malloc(sizeof(t_semicolon))))
		return (NULL);
    element->split_semicolon = split_semicolon;
    element->mask_semicolon = mask_semicolon;
    element->pipes = NULL;
	element->next = NULL;
	return (element);
}

void	ft_lstadd_back(t_semicolon **alst, t_semicolon *new)
{
	t_semicolon *lst;
	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
	}
}



void ft_print(t_semicolon *head)
{
	t_semicolon *current;
	current = head;

	while(current){
       // printf("in\n");
        printf("|%s|\n",current->split_semicolon);
        printf("|%s|\n",current->mask_semicolon);
        printf("\n***********************\n");
		//printf(" c= |%c| - i = |%d|\n",current->c, current->i);
		current = current->next;
	}
}
