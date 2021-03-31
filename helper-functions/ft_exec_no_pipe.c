#include "../header.h"
int ft_call(char **args)
{
     int i = 0;
     while (args[i])
         i++;
     int id = fork();
     if (id == 0)
        execve(args[0],args,NULL);
    wait(NULL);
return 1;
 }
int ft_exec_no_pipe(t_split *pi, char **path)
{
    t_split *space; 
    char **args;
    int i ;

    i = 0;
    space = pi->split;
    args = malloc(sizeof(char *) * (ft_nbr_args(space) + 1));
    while(space)
    {
        args[i++] = space->str;
        space = space->next;
    }
    args[i] = NULL;
    if(!(args[0] =ft_call_executable(ft_join("/",args[0]),path)))
        return 0;
    ft_call(args);
    return 1;
}