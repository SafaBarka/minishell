#include "../header.h"

char    *ft_n(char *s, unsigned int start, size_t len)
{
    size_t  i;
    char    *src;
    i = 0;
    if (s == NULL)
        return (NULL);
    if (start > ft_strlen(s))
        len = 0;
    src = (char*)malloc(len + 1);
    if (src == NULL)
        return (NULL);
    while (i < len && s[start] != '\0')
    {
        src[i] = s[start];
        i++;
        start++;
    }
    src[i] = '\0';
    return (src);
}
char    *ft_value(char *s)
{
    t_list *node;
    char *s1;
    node = export;
    while(node)
    {
        s1 = ft_n(node->content, 0,ft_position(node->content, '=')-1);
        if(ft_strcmp(s, s1) == 0)
        {
            s = ft_strchr(node->content, '=');
            return(s+1);
        }
        node = node->next;
    }
    return NULL;
}


void ft_replace_dollar(char **command, char **mask)
{
    int i = 0;
    int len = ft_strlen(*mask);
    int stop;
    char *name;
    char *tempc;
    char *tempm;
    char *s;
    while (i < len)
    {
        if((*mask)[i] == '$')
        {
            stop = i+1;
            while((*mask)[stop] =='v')
                stop++;

            name = ft_s(*command,i,stop - i);
            tempc = *command;
            tempm = *mask;

            *command = ft_join(ft_su(tempc,0,i) ,ft_value(name +1));
            *command = ft_join(*command , ft_su(tempc,stop,(len-1) - stop +1));

            *mask = ft_join(ft_su(tempm,0,i) ,ft_value(name +1));
            *mask = ft_join(*mask , ft_su(tempm,stop,(len-1) - stop +1));
            len = ft_strlen(*mask);
        //break;
        }
        i++;
    }
}