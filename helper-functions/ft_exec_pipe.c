#include "../header.h"

int ft_nbr_pipe(t_split *pipe)
{
    t_split *current;
    current = pipe;
    int i = 0;
    while(current)
    {
        if (current->is_p == 1)
            i++;
        current = current->next;
    }
    return i-1;
}

int ft_nbr_args(t_split *split){
     int i = 0 ;
     while(split)
     {
         i++;
         split = split->next;
     }
     return i;
}

int ft_args(char **args)
{
    int i = 0;
    while (args[i])
        i++;
    return i;
}

int ft_builtin(char *name)
{
     if(ft_strncmp(name,"export",7) != 0 && ft_strncmp(name,"env",4) != 0 && 
     ft_strncmp(name,"echo",5) != 0 &&
    ft_strncmp(name,"pwd",4) != 0 && ft_strncmp(name,"cd",3) != 0 &&
    ft_strncmp(name ,"unset",6) != 0 &&
    ft_strncmp(name,"exit",5) != 0)
        return 0;
    return 1;

}
char **ft_create_args(t_split *current, char **path)
{
    char **args;
    int i ;
    t_split *space;
    int out;

    i = 0;
    space = current->split;
    if(!(args = malloc(sizeof(char *) * ( ft_nbr_args(space)+ 1))))
        return 0;
    while(space)
    {
        ft_replace_dollar(&space->str, &space->mask);
        args[i++] = space->str;
        
        space = space->next;
    }
    args[i] = NULL;
    if(!ft_builtin(args[0]))
            args[0] = ft_call_executable(ft_join("/",args[0]),path);

    return args;
}

void ft_builtin_cmd(char **args)
{
     if(ft_strncmp(args[0],"export",7) == 0)
        ft_add_export(args, ft_args(args), 0);
    else if(ft_strncmp(args[0],"env",4) == 0)
        ft_sort_env(0, ft_args(args));
    else if(ft_strncmp(args[0],"pwd",4) == 0)
        ft_pwd(0, ft_args(args));
    else if (ft_strncmp(args[0],"cd",3) == 0)
        ft_cd(0,ft_args(args),args);
    else if (ft_strncmp(args[0],"unset",6) == 0)
        ft_unset(0,args,ft_args(args));
    else if (ft_strncmp(args[0],"exit",5) == 0)
        ft_exit(0,ft_args(args),args);
    else if (ft_strncmp(args[0],"echo",5) == 0)
        ft_echo(args + 1);
}


int ft_exec_pipe(t_split *head, char **path)
{
    int nbr; 
    t_split *current;
    t_split *space;
    char **args;
    int i;
    nbr = ft_nbr_pipe(head);
    int fd[2];
    int fd_in = 0;
    int pid;
    int f = 0;
    int fd_old;
    current = head;
    int out;
   
    while (nbr >= 0)
    {
        args = ft_create_args(current,path);
        if(nbr != 0)
            pipe(fd);
        if(ft_builtin(args[0]))
        {
            out = dup(1);
            if(current->next != NULL)
            {
                dup2(fd[1],1);
                close(fd[1]);
            }
            ft_builtin_cmd(args);
            dup2(out,1);
        }
        else{
            pid = fork();
            f++;
            if(pid == 0)
            {
                
                dup2(fd_in, 0);
                if(current->next != NULL)
                {
                    dup2(fd[1],1);
                    close(fd[1]);
                }
                close(fd[0]);
                execve(args[0], args,NULL);
             }
        }
        close(fd[1]);
        fd_old = fd_in;
        if (fd_old != 0 && fd_old !=1)
           close(fd_old);
        fd_in = fd[0];
        nbr--;
        current = current->next;
    }
    
   while(f > 0)
   {
        wait(NULL);
       f--;
   }
 
    return 1;
}