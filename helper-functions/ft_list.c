#include "../header.h"

void ft_store_split(t_split **head, char *s, char *mask)
{
  // printf("|%s|\n",s);
    if(!(*head))
        *head = ft_lstnew(s, mask);
    else
        ft_lstadd_back(head, ft_lstnew(s, mask));
    
}

t_split	*ft_lstlast(t_split *lst)
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

t_split	*ft_lstnew(char *split_semicolon, char *mask_semicolon)
{
	t_split *element;

	if (!(element = (t_split *)malloc(sizeof(t_split))))
		return (NULL);
    element->command = split_semicolon;
    element->mask = mask_semicolon;
    element->split = NULL;
	element->next = NULL;
	return (element);
}

void	ft_lstadd_back(t_split **alst, t_split *new)
{
	t_split *lst;
	if (*alst == NULL)
		*alst = new;
	else if (*alst && new)
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
	}
}



void ft_print(t_split *head)
{
	t_split *semicolon;
	t_split *pipe;
	t_split *space;

	semicolon = head;

	while(semicolon){
		ft_write("\e[1;31m{\e[0m\n");
        printf("\t\e[1;31m|%s|\e[0m\n",semicolon->command);
        printf("\t\e[1;31m|%s|\e[0m\n",semicolon->mask);
		
		 pipe = semicolon->split;
		 while(pipe)
		{
			ft_write("\t\e[1;32m{\e[0m\n");
			printf("\t\t\e[1;32m|%s|\e[0m\n",pipe->command);
        	printf("\t\t\e[1;32m|%s|\e[0m\n",pipe->mask);
			space = pipe->split;
			while(space)
			{
				ft_write("\t\t\e[1;34m{\e[0m\n");
				printf("\t\t\t\e[1;34m|%s|\e[0m\n",space->command);
        		printf("\t\t\t\e[1;34m|%s|\e[0m\n",space->mask);
				space = space->next;
				ft_write("\t\t\e[1;34m}\e[0m\n");
			}
		 	pipe = pipe->next;
			ft_write("\t\e[1;32m}\e[0m\n");
		 }
		semicolon = semicolon->next;
		ft_write("\e[1;31m}\e[0m\n");
	}
}