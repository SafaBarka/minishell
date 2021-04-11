#include "header.h"

int main(int argc , char *argv[] , char *envp[])
{
    char *line;
    int len ;
    char *mask;
    list = NULL;
    t_split *list;
    char **path;
    ft_write("\e[1;31m***********************\e[0m\n");
    ft_write("\e[1;31m         SHELL         \e[0m\n");
    ft_write("\e[1;31m***********************\e[0m\n\n\n"); 

    ft_add_list_envp(envp);
    line = NULL;
    // need to split the PATH 
    if(!(path = ft_path(envp)))
            return -1;
    while(1)
    {
        ft_write("\e[1;32mSHELL-$ \e[0m");
        if (get_next_line(0, &line) == -1)
            return 0;
        len = ft_strlen(line);
        if (len == 0)
            continue;
        //create the mask for line
        if(!(mask = ft_create_mask(line, len)))
            return 0;
        if (!ft_check_errors(mask, len))
            return 0;
        if(!ft_store(&list , line , mask , len))
            return 0;
        free(line);
        line = NULL;
        ft_print(list);
        //after storing data in  list  ; time to execute commands
        //ft_exec(&list,path);

       //ft_free_list(&list);
        list = NULL;
    }
}