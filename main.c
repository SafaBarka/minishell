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
    ft_write("\e[1;31m***********************\e[0m\n");
    ft_write("\e[1;31m         SHELL         \e[0m\n");
    ft_write("\e[1;31m***********************\e[0m\n\n\n");   

    char *line = NULL;
    int len = 0;
    while(1)
    {
        ft_write("\e[1;32mSHELL-$ \e[0m");
        
        get_next_line(0, &line);
        len = ft_strlen(line);
        char *mask = ft_create_mask(line, len);
        if (mask == NULL)
         return 0; 
        char **split = ft_split_semicolon(line, mask, len);
        //  printf("|%s|\n",line);
        // printf("|%s|\n",mask);
        ft_print_split(split);
        free(line); 
        free(mask);
        line = NULL;
        mask = NULL;
        continue;
    }
}

