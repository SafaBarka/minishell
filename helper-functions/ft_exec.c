#include "../header.h"

void ft_exec(t_split **v, char **path)
{
    t_split *semic;
    t_split *pipe;
    int i;
    semic = *v;
    while (semic)
    {
        pipe = semic->split;
        while(pipe)
        {
            if(pipe->is_p == 1)
            {
                
                ft_exec_pipe(pipe,path);
                break;
            }
            else if (pipe->is_p == 0)
            {
               // printf("comand = %s - mask = %s\n",semic->str,semic->mask);
                ft_exec_no_pipe(pipe,path);
            }
            pipe = pipe->next;
           
        }
        
        semic = semic->next;
    }
}