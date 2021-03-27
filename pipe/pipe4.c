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

void    loop_pipe(char ***cmd) 
{
  int   p[2];
  pid_t pid;
  int   fd_in = 0;
 p[0] = 0;

  while (*cmd != NULL)
    {
      pipe(p);
    
      if ((pid = fork()) == -1)
        {
          exit(EXIT_FAILURE);
        }
      else if (pid == 0)
        {
          dup2(p[0], 0); //change the input according to the old one 
          if (*(cmd + 1) != NULL)
            dup2(p[1], 1);
          close(p[0]);
          //execvp((*cmd)[0], *cmd);
          execve((*cmd)[0],*cmd,NULL);
          exit(EXIT_FAILURE);
        }
    
          wait(NULL);
          close(p[1]);
        //  fd_in = p[0]; //save the input for the next command
          cmd++;
        
    }
}

// int main(int argc , char *argv[], char *envp[])
// {
// //   char *ls[] = {"/bin/ls", NULL};
// //   char *grep[] = {"/usr/bin/grep", "pipe", NULL};
// //   char *wc[] = {"usr/bin/wc", NULL};
//   char *ls[] = {"/bin/ls", NULL};
//   char *grep[] = {"/usr/bin/grep", "pipe", NULL};
//   char *wc[] = {"usr/bin/wc", NULL};
//   //char **cmd[] = {ls, grep, wc, NULL};
//   char **cmd[] ={ls,grep,wc,NULL};

//   loop_pipe(cmd);
//   return (0);
// }

int main()
{
  char *cmd1[] = {"/bin/echo","hello", "world",NULL}; 
char *cmd3[] = {"/bin/cat",NULL};
    char *cmd2[] = {"/usr/bin/rev",NULL};
  char **cmd[] = {cmd1,cmd2,cmd3 ,NULL};
  loop_pipe(cmd);
  return (0);
}