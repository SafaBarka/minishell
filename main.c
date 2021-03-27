#include "header.h"

void ft_write(char *s)
{
    write(1, s, ft_strlen(s));
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
        if(len == 0)
            continue;
        ft_store_list(&v->semicolon, line,ft_create_mask(line, len), len);
        //ft_print(v->semicolon);
        ft_exec(v->semicolon);
        free(line); 
        line = NULL;
    }

}