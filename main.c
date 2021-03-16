#include "header.h"

void ft_write(char *s)
{
    write(1, s, ft_strlen(s));
}

void ft_print_split(char **s)
{
    int i = 0;
    while (s && s[i])
    {
        ft_write("|");
        ft_write(s[i]);
        ft_write("|\n");
        i++;
    }
}

 int ft_calc_args(t_split *split){
     int i = 0 ;
     while(split)
     {
         i++;
         split = split->next;
     }
     return i;
 }

 void ft_print_args(char **args)
 {
     int i = 0;
     while (args[i])
     {
         printf("|%s|\n",args[i]);
         i++;
     }
 }

 void ft_call(char **args)
 {
        execve(args[0],args,NULL);
 }
int main(int argc , char *argv[] , char *envp[]){

    v = malloc(sizeof(t_var));
    v->semicolon = NULL;
    ft_write("\e[1;31m***********************\e[0m\n");
    ft_write("\e[1;31m         SHELL         \e[0m\n");
    ft_write("\e[1;31m***********************\e[0m\n\n\n");   

    char *line = NULL;
    int len = 0;
    while(1)
    {
        ft_write("\e[1;32mSHELL-$ \e[0m");
        if (get_next_line(0, &line) == -1)
        {
            ft_write("something wrong happened\n");
            return -1;
        }
        len = ft_strlen(line);
        if (len == 0)
            continue;
        ft_store_list(&v->semicolon, line,ft_create_mask(line, len), len);

       
        t_split *semicolon = v->semicolon;
        t_split *pipe ;
        t_split *space;
        int nbr = 0;
        char **args;
        int i = 0;
        char *path;
        int id = -1 ;
        while (semicolon)
        {
                pipe  = semicolon->split;
                while (pipe)
                {
                   
                        i = 0;
                        space = pipe->split;
                        nbr = ft_calc_args(space);
                        args = malloc(sizeof(char *) * (nbr +1));
                        while (space)
                        {
                            args[i] = space->command;
                            i++;
                            space = space->next;
                        }
                        id = fork();
                        if (id == 0)
                        {
                            args[i] = NULL;
                            path = ft_call_executable(ft_strj("/",args[0]),ft_find_path(envp));
                            args[0] = path;
                            ft_call(args);
                        }
                        if (id != 0)
                            wait(NULL);
                        pipe = pipe->next;
                }
             semicolon = semicolon->next;
        }
        
        free(line); 
        line = NULL;
        v->semicolon = NULL;
        continue;
    }
    }

