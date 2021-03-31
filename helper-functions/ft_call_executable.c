#include "../header.h"

char *ft_call_executable(char *command_name,char **split_path)
{
    int i = 0 ;
    struct stat stats;
    char *path;
    while (split_path[i])
    {
        path = ft_join(split_path[i],command_name);
        if(stat(path,&stats) == 0)
        {
            if (stats.st_mode & X_OK)
               return path;
            else 
				ft_write("Permisison denied\n");
            break;
        }
        i++;
    }
    if (split_path[i] == NULL)
        ft_write("command not found\n");
    return NULL;

}