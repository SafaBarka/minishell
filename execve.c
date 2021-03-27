#include <stdio.h>
#include "../header.h"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
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
char	*ft_substr(char  *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	str = NULL;
	if (s == NULL)
		return (NULL);
	else if (start >= strlen((char *)s))
		len = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		i = (size_t)start;
		while (i < (len + start))
		{
			str[j] = ((char*)s)[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}
static int		count_words(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s == NULL || !s[i])
		return (0);
	while (s[i] == c)
		i++;
	if (s[i])
	{
		count++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char		**free_tab(int i, char **str)
{
	while (--i >= 0)
	{
		free(str[i]);
	}
	free(str);
	return (NULL);
}

static char		**result(int i, int cw, char **str)
{
	if (i == cw)
		str[i] = NULL;
	return (str);
}

char			**ft_spl(char *s, char c)
{
	int		start;
	int		end;
	int		i;
	int		cw;
	char	**str;

	start = 0;
	end = 0;
	i = 0;
	cw = count_words((char *)s, c);
	if (s == NULL || !(str = (char **)malloc(sizeof(char *) * (cw + 1))))
		return (NULL);
	while (((char *)s)[end] && i != cw)
	{
		while (((char *)s)[end] && ((char *)s)[end] == c)
			end++;
		start = end;
		end++;
		while (((char *)s)[end] && ((char *)s)[end] != c)
			end++;
		if (i < cw)
			if (!(str[i++] = ft_substr(s, start, (end - 1) - start + 1)))
				return (free_tab(i, str));
	}
	return (result(i, cw, str));
}

int ft_print_split(char **split)
{
    int i = 0;
    if (!split)
        return -1;
    while(split[i])
    {   
           // printf("path %d = %s\n",i,split[i]);
            i++;
    }
    return 1;
}
int		ft_strncmp(char *s1,char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main(int argc, char *argv[] , char *envp[])
{
    char *path;
    int i = 0;
    char **split = NULL;
	struct stat stats;
    while (envp[i] != NULL)
    {
        if (ft_strncmp("PATH=",envp[i],5) == 0)
        {
            path = envp[i] + 5;
            break;
        }
        i++;
    }
    split = ft_spl(path,':');
   i = 0;
   char *s = "/nam" ;
   while(split[i])
   {
	   if(stat(ft_strj(split[i] , s),&stats) == 0)
	   {
		 //  printf("path = |%s|\n",ft_strj(split[i] , s));
		 //   printf("\nFile access: ");
    
    		if (stats.st_mode & X_OK)
        		ft_write("execute");
			else 
				ft_write("Permisison denied\n");
			break;
	   }
	   i++;
   }
   if (split[i] == NULL)
		printf("command not found\n");

   int fd = open("/usr/bin/name",O_RDONLY);
  // printf("fd = |%d|\n",fd);
}
