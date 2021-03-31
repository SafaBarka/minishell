
#include "../header.h"

int ft_store(t_split **head, char *line, char *mask , int len)
{
      t_split *semicolon;
      t_split *pipe;

      ft_split(head, line, mask, len,';');
    
      semicolon = *head;
        while (semicolon)
        {
            if(!ft_split(&semicolon->split, semicolon->str, semicolon->mask, ft_strlen(semicolon->str),'|'))
                return 0;
            pipe = semicolon->split;
            while (pipe){
                if(!(ft_split(&pipe->split, pipe->str, pipe->mask, ft_strlen(pipe->str),'S')))
                    return 0;
                pipe = pipe->next;
            }
            semicolon = semicolon->next;
        }
       // ft_print(*head);
        return 1;
}