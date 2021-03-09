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
    int len = 0;
    while(1)
    {
        ft_write("\e[1;32mSHELL-$ \e[0m");
        
        get_next_line(0, &line);
        len = ft_strlen(line);
        char *mask = ft_create_mask(line, len);
        if (mask == NULL)
         return 0; 
        // ft_split_semicolon(line, mask, len);
          printf("|%s|\n",line);
         printf("|%s|\n",mask);
        free(line); 
        free(mask);
        line = NULL;
        mask = NULL;
        continue;
    }
}

