#include "../header.h"

int ft_include(char *s,int len , char c)
{
    int i = 0 ; 
    while (i < len)
    {
        if (s[i] == c)
            return 1;
        i++;
    }
    return 0;
}

char *ft_dollar(char *old_mask, char *line, int len)
{
    char *no_var;
    int i;
   
    no_var = " '\")%,;./>\\^+:<=]";
    i = 0;

    while (i < len)
    {
        if(old_mask[i] == 36)
        {
            while (i+1 < len)
            {
                if (ft_include(no_var, ft_strlen(no_var) , line[i+1]) == 0 && old_mask[i+1] != '$')
                    old_mask[i+1] ='v';
                else
                    break;
                i++;
            }
        }
        i++;
    }
    return old_mask;
}