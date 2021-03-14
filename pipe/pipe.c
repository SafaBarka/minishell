#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

// how to communicate between processes.
// a pipe is basically in-memory file
// a file that you can write and read from it 
// if we want to open a pipe() we call just the function pipe()
int main(int argc, char *argv[]){
    int fd[2];
    //fd[0] - read from
    //fd[1] - write to
    if(pipe(fd) == -1)
    {
        printf("an error occured with opening the pipe\n");
        return 1;
    }
    
    int id = fork();
    //file descriptors are inherited
    if(id == 0)
    {
        int x ;
        printf("Input a number : ");
        //we want that x be sent to the parent process to the child process
        scanf("%d",&x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    }
    return 0;
}
