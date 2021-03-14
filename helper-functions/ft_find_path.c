#include "../header.h"

char *ft_find_path(char *envp[])
{
    printf("|%s|\n",envp[0]);
     char **split = NULL;
     char *path;
     int i = 0;
     struct stat stats;
     while (envp[i] != NULL)
     {
         if(ft_strncmp("PATH=",envp[i],5) == 0)
         {
             path = envp[i] + 5;
            break;
         }
         i++;
     }

// printf("path = |%s|\n",path);
   // split = ft_split_path(path,':');
    
    //return split;
    return path;
    
}