#include "../header.h"

int ft_semicolon_error(char *mask, int len)
{
    
    int i = 0;
    if (mask[0] == ';')
    {
        ft_write("bash: syntax error near unexpected token `;'\n");
        return 0;
    }
    i++;
    while (i < len)
    {
        if (mask[i] == ';' && mask[i+1] == ';')
        {
            ft_write("bash: syntax error near unexpected token `;;'\n");
            return 0;
        }
        i++;
    }
    return 1 ;
}

int ft_quotes_error(char *mask, int len){

    int i;
    int nbr_dq;
    int nbr_sq;

    i = 0;
    nbr_dq = 0;
    nbr_sq = 0;

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
        return 0;
    }
    else if (nbr_sq %2 != 0)
    {
        ft_write("single quotes are not closed\n");
        return 0;
    }
    return 1;
}

int ft_check_errors(char *mask, int len)
{
    if(!ft_semicolon_error(mask,len))
        return 0;
    if(!ft_quotes_error(mask,len))
        return 0;
    return 1;
}