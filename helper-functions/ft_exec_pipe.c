#include "../header.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int ft_nbr_pi(t_split *pi)
{
    t_split *current = pi;
    int i = 0;
    while(current)
    {
        if (current->pipe == 1)
            i++;
        current = current->next;
    }
    return i-1;
}

void ft_exec_no_pipe(t_split *pi, char **envp)
{
    t_split *space; 
    char **args;
    int i ;
    char *path;

    i = 0;
    space = pi->split;
    args = malloc(sizeof(char *) * (ft_calc_args(space) + 1));
    while(space)
    {
        args[i++] = space->command;
        space = space->next;
    }
    args[i] = NULL;
    path = ft_call_executable(ft_strj("/",args[0]),ft_find_path(envp));
    args[0] = path;
    ft_call(args);

}
void ft_exec_pipe(t_split *pi, char **envp)
{
    t_split *space; 
    char **args;
    int i ;
    char *path;

    int   p[2];
    pid_t pid;
    int   fd_in = 0;

    while(pi)
    {
        i = 0;
        space = pi->split;
        args = malloc(sizeof(char *) * (ft_calc_args(space) + 1));
        while(space)
        {
            args[i++] = space->command;
            space = space->next;
        }
        args[i] = NULL;
        path = ft_call_executable(ft_strj("/",args[0]),ft_find_path(envp));
        args[0] = path;
        pipe(p);
        if ((pid = fork()) == -1)
            exit(EXIT_FAILURE);
        else if (pid == 0)
        {
            dup2(fd_in,0);
            if (pi->next != NULL)
                dup2(p[1],1);
            close(p[0]);
            execve(args[0],args,NULL);
        }
        wait(NULL);
        close(p[1]);
        fd_in = p[0];
        pi = pi->next;
    }
}