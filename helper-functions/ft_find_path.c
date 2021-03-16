#include "../header.h"

char **ft_find_path(char *envp[])
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
char	*ft_strj(char  *s1, char  *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_call_executable(char *command_name,char **split_path)
{
    int i = 0 ;
    struct stat stats;
    char *path;
    while (split_path[i])
    {
        path = ft_strj(split_path[i],command_name);
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