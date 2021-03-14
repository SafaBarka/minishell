#include "../header.h"

void ft_store_split(t_split **head, char *s, char *mask, char c,int len)
{
  // printf("|%s|\n",s);

    t_split *new = ft_lstnew(s,mask);
	new->pipe = 0;
	new->space = 0;
	new->semicolon = 0;
	//if(c == ';' && len != ft_strlen(s))
	//	new->semicolon = 1;
	//else if (c == 'S' && len != ft_strlen(s))
		//new->space = 1;
	if (c ==  '|' && len != ft_strlen(s))
		new->pipe = 1;
    if(!(*head))
        *head = new;
    else
        ft_lstadd_back(head, new);
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
		//printf("\t\e[1;31m|%d|\e[0m\n",semicolon->semicolon);
        //printf("\t\e[1;31m|%d|\e[0m\n",semicolon->space);
		printf("\t\e[1;31m|%d|\e[0m\n",semicolon->pipe);
		 pipe = semicolon->split;
		 while(pipe)
		{
			ft_write("\t\e[1;32m{\e[0m\n");
			printf("\t\t\e[1;32m|%s|\e[0m\n",pipe->command);
        	printf("\t\t\e[1;32m|%s|\e[0m\n",pipe->mask);
			//printf("\t\t\e[1;32m|%d|\e[0m\n",pipe->semicolon);
        	//printf("\t\t\e[1;32m|%d|\e[0m\n",pipe->space);
			printf("\t\t\e[1;32m|%d|\e[0m\n",pipe->pipe);
			space = pipe->split;
			while(space)
			{
				ft_write("\t\t\e[1;34m{\e[0m\n");
				printf("\t\t\t\e[1;34m|%s|\e[0m\n",space->command);
        		printf("\t\t\t\e[1;34m|%s|\e[0m\n",space->mask);
				//printf("\t\t\t\e[1;34m|%d|\e[0m\n",space->semicolon);
        		//printf("\t\t\t\e[1;34m|%d|\e[0m\n",space->space);
				printf("\t\t\t\e[1;34m|%d|\e[0m\n",space->pipe);
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
///https://www-users.cs.umn.edu/~kauffman/4061/05-io-files-pipes.pdf