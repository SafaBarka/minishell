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

int main(){

    v = malloc(sizeof(t_var));
    v->semicolon = NULL;
    ft_write("\e[1;31m***********************\e[0m\n");
    ft_write("\e[1;31m         SHELL         \e[0m\n");
    ft_write("\e[1;31m***********************\e[0m\n\n\n");   

    char *line = NULL;
    int len = 0;
    t_split *semicolon;
    t_split *pipe;
    while(1)
    {
        ft_write("\e[1;32mSHELL-$ \e[0m");
        
        get_next_line(0, &line);
        len = ft_strlen(line);
        char *mask = ft_create_mask(line, len);
        ft_split(&v->semicolon, line, mask, len,';');
       
        //ft_print(v->semicolon);
        //ft_store_split_semicolon("hello","pppp");
        //ft_store_split_semicolon("best","pppp");
        semicolon = v->semicolon;
        while (semicolon)
        {
            ft_split(&semicolon->split, semicolon->command, semicolon->mask, ft_strlen(semicolon->command),'|');
            pipe = semicolon->split;
            while (pipe){
                ft_split(&pipe->split, pipe->command, pipe->mask, ft_strlen(pipe->command),'S');
                pipe = pipe->next;
            }
            semicolon = semicolon->next;
        }

        ft_print(v->semicolon);
        free(line); 
        free(mask);
        line = NULL;
        mask = NULL;
        v->semicolon = NULL;
        continue;
    }
}

