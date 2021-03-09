#include "header.h"

void ft_write(char *s)
{
    write(1, s, ft_strlen(s));
}


int main(){
    ft_write("\e[1;31m***********************\e[0m\n");
    ft_write("\e[1;31m         SHELL         \e[0m\n");
    ft_write("\e[1;31m***********************\e[0m\n\n\n");   

    char *line = NULL;

    while(1)
    {
        ft_write("\e[1;32mSHELL-$ \e[0m");
       
        get_next_line(0, &line);
        if(!ft_initialize())    
            return 0;
       char *mask = ft_store_printable(line, ft_strlen(line));
       printf("|%s|\n",line);
       printf("|%s|\n",mask);
        // printf("------backslash--------\n");
        // ft_print(v->p_backslash);
        // printf("------double quotes--------\n");
        // ft_print(v->p_dq);
        // printf("------single quotes--------\n");
        // ft_print(v->p_sq);
        // printf("------semicolon--------\n");
        // ft_print(v->p_semicolon);
        // printf("------dollar--------\n");
        // ft_print(v->p_dollar);
        
       

        free(line); 
        line = NULL;
        continue;
    }
}

