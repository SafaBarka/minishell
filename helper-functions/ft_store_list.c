#include "../header.h"
t_split	*ft_lstnew(char *str, char *mask)
{
	t_split *element;

	if (!(element = (t_split *)malloc(sizeof(t_split))))
		return (NULL);
    element->str = str;
    element->mask = mask;              
    element->split = NULL;
	element->next = NULL;
	return (element);
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


int ft_store_list(t_split **list, char *str, char *mask, char c,int len)
{
    t_split *new;
	
	if(!(new = ft_lstnew(str,mask)))
		return 0;
	new->is_p = 0;
	if (c ==  '|' && len != ft_strlen(str))
		new->is_p = 1;
    if(!(list))
        list = &new;
    else
        ft_lstadd_back(list, new);
	return 1;
}






void ft_print(t_split *head)
{
	t_split *semicolon;
	t_split *pipe;
	t_split *space;

	semicolon = head;

	while(semicolon){
		ft_write("\e[1;31m{\e[0m\n");
        printf("\t\e[1;31m|%s|\e[0m\n",semicolon->str);
        printf("\t\e[1;31m|%s|\e[0m\n",semicolon->mask);
		printf("\t\e[1;31m|%d|\e[0m\n",semicolon->is_p);
		 pipe = semicolon->split;
		 while(pipe)
		{
			ft_write("\t\e[1;32m{\e[0m\n");
			printf("\t\t\e[1;32m|%s|\e[0m\n",pipe->str);
        	printf("\t\t\e[1;32m|%s|\e[0m\n",pipe->mask);
			printf("\t\t\e[1;32m|%d|\e[0m\n",pipe->is_p);
			space = pipe->split;
			while(space)
			{
				ft_write("\t\t\e[1;34m{\e[0m\n");
				printf("\t\t\t\e[1;34m|%s|\e[0m\n",space->str);
        		printf("\t\t\t\e[1;34m|%s|\e[0m\n",space->mask);
				printf("\t\t\t\e[1;34m|%d|\e[0m\n",space->is_p);
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