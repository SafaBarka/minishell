#include "header.h"
int p= 0;
typedef struct      command
{
                    char **argv;
}                   command;
// int is_builtin(char **args)
// {
//     int i;
//  int len;
//     int ret;
//  i = -1;
//     len =  ft_strlen(args[0]);
//  while (++i < 4)
//     {
//         if (ft_strncmp(args[0], builtin_str[i], len) == 0)
//         {
//             ret = (*builtin_func[i])(args); 
//             return (1);
//         }
//     }
//     return 0;
// }
int spawn_process (int in, int out, struct command *cmd)
{
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        if (in != 0)
        {
            dup2 (in, 0);
            close (in);
        }
        if (out != 1)
        {
            dup2 (out, 1);
            close (out);
        }
        // if(is_builtin(cmd)) {execute builtin cmds}
        execve(cmd->argv[0], cmd ->argv, 0);
    }
    else if (pid < 0)
        printf("Parent: oops! can not create a child (my pid is %d)\n", getpid());
    return pid;
}
int fork_pipes (int n, command *cmd)
{
    int fd[2];
    int i;
    int in;
    int out;
    
    int k = 0;
    pid_t pid;
    i = 0;
    in = 0;
    while(i < n - 1)
    {
        p++;
        pipe(fd);
        out = fd[1];
        spawn_process (in, out, cmd + i);
        close(fd[1]);
        in = fd[0];
        i++;
    }
    out = 1;
    p++;
    pid = spawn_process (in, out, cmd + i);
    close(in);
    close(fd[0]);

    return (0);
    wait(NULL);
}
// cat |ls
// cat |grep "o"
// cat | ls
int main ()
{
    char *ls[] = { "/bin/ls", 0 };
    char *cat[] = { "/bin/cat", 0 };
    // char *rev[] = { "/usr/bin/rev", 0 };
    command cmd[] = {{cat }, {ls} };
    return fork_pipes (2, cmd);
   
}