#include "../header.h"

int ft_calc_args(t_split *split){
     int i = 0 ;
     while(split)
     {
         i++;
         split = split->next;
     }
     return i;
}

void ft_call(char **args)
{
     int i = 0;
     while (args[i])
         i++;
     int id = fork();
     if (id == 0)
        execve(args[0],args,NULL);
    wait(NULL);
 }

void ft_exec(t_split *v, char *envp[])
{
    t_split *semicolon;
    t_split *pipe;
    t_split *space;
    char **args;
    int i;
    char *path;

    semicolon = v;
    while (semicolon)
    {
        pipe = semicolon->split;
        while(pipe)
        {
            if(pipe->pipe == 1)
            {
                ft_exec_pipe(pipe,envp);
                break;
            }
            else if (pipe->pipe == 0)
                ft_exec_no_pipe(pipe,envp);
            pipe = pipe->next;
           
        }
        semicolon = semicolon->next;
    }
}