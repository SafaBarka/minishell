#include "../header.h"
char	*ft_strj(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

char	*ft_su(char  *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	str = NULL;
	if (s == NULL)
		return (NULL);
	else if (start >= ft_strlen((char *)s))
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

char *ft_remove_bq(char **s, char **m)
{
    int len = ft_strlen(*s);
    int i = 0;
    while (i < len)
    {
        if((*m)[i] == '\"' || (*m)[i] == '\\' )
        {
            *s = ft_strj(ft_su(*s,0,i) , ft_su(*s,i+1,(len-1 -(i+1) + 1)));
            
            *m = ft_strj(ft_su(*m,0,i) , ft_su(*m,i+1,(len-1 -(i+1) + 1)));
            len = ft_strlen(*s);
        }
        i++;
    }
    return NULL;
}