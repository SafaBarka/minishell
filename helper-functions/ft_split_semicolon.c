#include "../header.h"

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
    
    while (i < len)
    {
        if(mask[i] == ';' && i + 1 < len)
            count++;
        i++;
    }
    return count; 

}
int ft_split_semicolon(char *s , char *mask , int len)
{
    if(ft_check_semicolon_error(mask,len) == -1)
        return -1;
    if(ft_check_closed_quotes(mask,len) == -1)
        return -1;
    int count_semicolons = ft_nbr_words_semicolon(mask, len);
    printf("count = %d\n",count_semicolons);
    int i = 0;
    
   return 1;
}