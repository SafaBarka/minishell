#include "../header.h"

char **ft_path(char *envp[])
{
     char **split = NULL;
     char *path;
     int i = 0;
     while (envp[i] != NULL)
     {
         if(ft_strncmp("PATH=",envp[i],5) == 0)
         {
            path = envp[i] + 5;
            break;
         }
         i++;
     }
    split = ft_split_path(path,':');
    return split;
}