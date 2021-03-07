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
    char **split;
    v = malloc(sizeof(t_v));
    while(1)
    {
        ft_write("\e[1;32mSHELL-$ \e[0m");
       
        get_next_line(0, &line);
        ft_initialize();
        ft_store_printable(line,ft_strlen(line));

       printf("----------backslassh---------\n");
       ft_print_backslash();
        printf("----------semicolon----------\n");
       ft_print_semicolon();
       printf("------------dollar-------------\n");
       ft_print_dollar();
       printf("----------double quotes---------\n");
       ft_print_dq();
       printf("----------single quotes---------\n");
       ft_print_sq();
       
    
        //printf("squotes = |%s|\nsemicolon = |%s|\ndollar = |%s|\n",v->print_squotes,v->print_semicolon,v->print_dollar);
        free(line); 
        line = NULL;
        continue;
    }
}