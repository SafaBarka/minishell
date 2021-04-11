#include "../header.h"
int ft_call(char **args)
{
     int i = 0;
    while (args[i])
        i++;
    if(ft_strncmp(args[0],"export",7) == 0)
       ft_add_export(args,i,0);
    else if (ft_strncmp(args[0],"env",4) == 0)
        ft_sort_env(0,i);
    else if (ft_strncmp(args[0],"pwd",4) == 0)
        ft_pwd(0,i);
    else if (ft_strncmp(args[0],"cd",3) == 0)
        ft_cd(0,i,args);
    else if (ft_strncmp(args[0],"unset",6) == 0)
        ft_unset(0,args,i);
    else if (ft_strncmp(args[0],"exit",5) == 0)
        ft_exit(0,i,args);
    else
    {
         int id = fork();
    if (id == 0)
       execve(args[0],args,NULL);
    }
   
    wait(NULL);
return 1;
 }
int ft_exec_no_pipe(t_split *pi, char **path)
{
    t_split *space; 
    char **args;
    char **masks;
    int i ;
    char *cmd;

    i = 0;
    space = pi->split;
    args = malloc(sizeof(char *) * (ft_nbr_args(space) + 1));
    while(space)
    {
        args[i++] = space->str;
        ft_replace_dollar(&space->str, &space->mask);
        space = space->next;
    }
    args[i] = NULL;
     if( ft_strncmp(args[0], "cd",3) != 0 
        && ft_strncmp(args[0], "pwd",4) != 0 && ft_strncmp(args[0],"export",7) != 0 && 
        ft_strncmp(args[0],"unset",6) != 0 && ft_strncmp(args[0], "env",4) != 0 
        && ft_strncmp(args[0], "exit",5) != 0)
            if(!(args[0] =ft_call_executable(ft_join("/",args[0]),path)))
                return 0;
    ft_call(args);
    return 1;
}