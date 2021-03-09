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
       char *mask = ft_create_mask(line, ft_strlen(line));
       if (mask == NULL)
        return 0; 
        printf("|%s|\n",line);
        printf("|%s|\n",mask);
      
       

        free(line); 
        line = NULL;
        continue;
    }
}

