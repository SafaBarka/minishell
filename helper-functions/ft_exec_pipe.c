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
    int files[10];
    int k = 0;
    int cmd = 0;
    current = head;
    while (nbr >= 0)
    {
         i = 0;
         space = current->split;
     
       if(!(args = malloc(sizeof(char *) * ( ft_nbr_args(space)+ 1))))
           return 0;
        while(space)
        {
            args[i++] = space->str;
            space = space->next;
        }
        args[i] = NULL;
        args[0] = ft_call_executable(ft_join("/",args[0]),path);
        if(nbr != 0)
            pipe(fd);
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
        cmd++;
        close(fd[1]);
        fd_in = fd[0];
        files[k] = fd_in;
        k++;
        nbr--;
        current = current->next;
    }
    while (k >= 0)
    {
        close(files[k]);
        k--;

    }
    while(f > 0)
    {
        wait(NULL);
        f--;
    }
    return 1;
}