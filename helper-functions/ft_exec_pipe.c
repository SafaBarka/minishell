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
    int fd[2];
    int fd_in = 0;
    int pid ;

    current = head;
    nbr = ft_nbr_pipe(head);
    while (nbr >= 0)
    {
        i = 0;
        space = current->split;
        if(!(args = malloc(sizeof(char *) * (ft_nbr_args(space) + 1))))
            return 0;
        while(space)
        {
            args[i++] = space->str;
            space = space->next;
        }
        args[i] = NULL;
        if(!(args[0] = ft_call_executable(ft_join("/",args[0]),path)))
            return 0;
        
        //pipe execution
        if(nbr != 0)
            pipe(fd);
        pid = fork();
        if(pid == 0)
        {
            dup2(fd_in, 0);
            if(current->next != NULL)
                dup2(fd[1],1);
            close(fd[0]);
            execve(args[0],args,NULL);
        }
        close(fd[1]);
        fd_in = fd[0];

        //free the double pointer
        int k = 0;
        while (args[k])
            free(args[k++]);

        current = current->next;   
        nbr--;
    }

    nbr = ft_nbr_pipe(head) + 1;
    int j = -1;
    while (++j < nbr)
        wait(NULL);
        
    return 1;
}