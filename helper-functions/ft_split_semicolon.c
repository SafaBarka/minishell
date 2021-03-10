#include "../header.h"
char	*ft_substr(char  *s, unsigned int start, size_t len)
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
int ft_check_semicolon_error(char *mask, int len)
{
    
    int i = 0;
    if (mask[0] == ';')
    {
        ft_write("bash: syntax error near unexpected token `;'\n");
        return -1;
    }
    i++;
    while (i < len)
    {
        if (mask[i] == ';' && mask[i+1] == ';')
        {
            ft_write("bash: syntax error near unexpected token `;;'\n");
            return -1;
        }
        i++;
    }
    return 1 ;
}
int ft_check_closed_quotes(char *mask, int len){
    int i = 0;
    int nbr_dq = 0;
    int nbr_sq = 0;
    while (i < len)
    {
        if(mask[i] == 34)
            nbr_dq++;
        else if (mask[i] == 39)
            nbr_sq++;
        i++;
    }
    if (nbr_dq %2 != 0)
    {
        ft_write("double quotes are not closed\n");
        return -1;
    }
    else if (nbr_sq %2 != 0)
    {
        ft_write("single quotes are not closed\n");
        return -1;
    }
    return 1;
}

int ft_nbr_words_semicolon(char *mask, int len)
{
    int i = 0;
    int count = 0;

    if (len == 0)
        return 0;
    count++;
    i++;
    while (i < len)
    {
        if(mask[i] == ';' && i + 1 < len && mask[i+1] != ';')
            count++;
        i++;
    }
    return count; 

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
char **ft_split_semicolon(char *s , char *mask , int len)
{
    int cw;
    char **str;
    int start = 0;
    int end = 0;
    int i = 0;

    if (s == NULL)
        return NULL;
    if(ft_check_semicolon_error(mask,len) == -1)
        return NULL;
    if(ft_check_closed_quotes(mask,len) == -1)
        return NULL;
    cw = ft_nbr_words_semicolon(mask, len);
    if (!(str = malloc(sizeof(char *) * (cw +1))))
        return NULL;
    while (((char *)mask)[end] && i != cw)
	{
        while (((char *)mask)[end] && ((char *)mask)[end] == ';')
			end++;
		start = end;
		end++;
		while (((char *)mask)[end] && ((char *)mask)[end] != ';')
			end++;
		if (i < cw)
			if (!(str[i++] = ft_substr(s, start, (end - 1) - start + 1)))
				return (free_tab(i, str));
	}
	return (result(i, cw, str));
   return NULL;
}