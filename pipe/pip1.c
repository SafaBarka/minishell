#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd[2];
    //fd[1] write end of the pipe
    //fd[0] read end of the pipe
    if(pipe(fd) == -1)
    {
        return 1;
    }
    int pid1 = fork();
    if (pid1 < 0)
        return 2;
    if(pid1 == 0){
        //child process 1 (ping)
        //passing the standard output fd[1]
        dup2(fd[1],STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        //execlp("ping", "ping", "-c" ,"5","google.com", NULL);
        execlp("echo", "echo", "hello" , NULL);
    }
    int pid2 = fork();
    if(pid2 < 0)
    {
        return 3;
    }
    if(pid2 == 0)
    {
        //child process 2 (grep)
        dup2(fd[0],STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        //execlp("grep","grep","rtt",NULL);
        execlp("cat","-e",NULL);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);

    return 0;
}