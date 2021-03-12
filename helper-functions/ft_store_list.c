
#include "../header.h"

int ft_store_list(t_split **head, char *line, char *mask , int len)
{
      t_split *semicolon;
      t_split *pipe;

      ft_split(head, line, mask, len,';');
    
      semicolon = *head;
        while (semicolon)
        {
            ft_split(&semicolon->split, semicolon->command, semicolon->mask, ft_strlen(semicolon->command),'|');
            pipe = semicolon->split;
            while (pipe){
                ft_split(&pipe->split, pipe->command, pipe->mask, ft_strlen(pipe->command),'S');
                pipe = pipe->next;
            }
            semicolon = semicolon->next;
        }
        return 1;
}