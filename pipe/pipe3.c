#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "../header.h"
#include <string.h>

void ft_write(char *s)
{
    write(1, s, strlen(s));
}
int main(int argc, char *argv[]){
    int fd[2][2];
    char *buff;
    buff = malloc(sizeof(char) *  60 + 1);
    pipe(fd[0]) ; pipe(fd[1]);

    
    char *cmd1[] = {"/bin/echo","hello", "world",NULL}; 
    char *cmd3[] = {"/bin/cat",NULL};
    char *cmd2[] = {"/usr/bin/rev",NULL};

    int pid1= fork();
    if(pid1 == 0)
    {
        dup2(fd[0][1],STDOUT_FILENO);
        execve(cmd1[0],cmd1,NULL);
        close(fd[0][1]);
        close(fd[0][0]);

    }

    dup2(fd[0][0],STDIN_FILENO);
    int pid2 = fork();
    if(pid2 == 0)
    {
      
        dup2(fd[1][1],STDOUT_FILENO);
        execve(cmd2[0],cmd2,NULL);
        close(fd[1][1]);
        close(fd[1][0]);
    }
   
    // dup2(fd[1][0],STDIN_FILENO);

    // int pid3= fork();
    // if(pid3 == 0)
    // {
    //     execve(cmd3[0],cmd3,NULL);
    // }

    wait(NULL);
     read(fd[1][0],buff,12);
    ft_write(buff);
    close(fd[0][1]); close(fd[0][0]); close(fd[1][1]); close(fd[1][0]);
}

//https://stackoverflow.com/questions/916900/having-trouble-with-fork-pipe-dup2-and-exec-in-c/