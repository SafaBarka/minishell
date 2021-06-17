#include "../header.h"

int ft_semicolon_error(char *mask, int len, int *pos)
{
 
    if(*pos == 0)
        return ft_error("minishell: syntax error near unexpected token `;'");
    (*pos)++;

    while(*pos < len && mask[*pos] == 'S')
        (*pos)++;
    if(*pos < len && mask[*pos] == '|')
        return ft_error("minishell: syntax error near unexpected token `|'");
    if(*pos < len && mask[*pos] == ';')
        return ft_error("minishell: syntax error near unexpected token `;'");

     return 1 ;
}

int ft_single_quote(char *mask, int len , int *pos)
{
    int nbr_sq;
    nbr_sq = 0;
    while((*pos) < len)
    {
        if(mask[*pos] == 39)
            nbr_sq++;
        (*pos)++;
    }
    if (nbr_sq %2 != 0)
    {
        ret = 2;
	    replace_ret(export);
        return ft_error("minishell: unexpected EOF while looking for matching `''");
         
    }
    return 1;
}

int ft_double_quote(char *mask, int len , int *pos)
{
    int nbr_dq;
    nbr_dq = 0;
    while((*pos) < len)
    {
        if(mask[*pos] == 34)
            nbr_dq++;
        (*pos)++;
    }
  //  printf("nbr = %d\n",nbr_dq);
    if (nbr_dq %2 != 0)
    {
         ret = 2;
	    replace_ret(export);
        return ft_error("minishell: unexpected EOF while looking for matching `\"'");
       
    }
    return 1;
}

int ft_pipe_error(char *mask , int len , int *pos)
{
    if(*pos == 0)
        return ft_error("minishell: syntax error near unexpected token `|'");
    if(*pos == len - 1)
        return ft_error("minishell: syntax error near unexpected token `|'");
    (*pos)++;

    while(*pos < len && mask[*pos] == 'S')
        (*pos)++;
    if(*pos < len && mask[*pos] == ';')
        return ft_error("minishell: syntax error near unexpected token `;'");
    if(*pos < len && mask[*pos] == '|')
        return ft_error("minishell: syntax error near unexpected token `|'");

     return 1 ;
  
}

int ft_in_error(char *mask , int len , int *pos)
{
    if(*pos == len - 1)
        return ft_error("minishell: syntax error near unexpected token `newline'");
    (*pos)++;

    while(*pos < len && mask[*pos] == 'S')
        (*pos)++;
    if(*pos < len && mask[*pos] == '|')
        return ft_error("minishell: syntax error near unexpected token `|'");
    else if (*pos < len && mask[*pos] == ';')
        return ft_error("minishell: syntax error near unexpected token `;'");
    else if(*pos < len && mask[*pos] == '>')
        return ft_error("minishell: syntax error near unexpected token `>'");
    if(*pos < len && mask[*pos] == '<')
        return ft_error("minishell: syntax error near unexpected token `<'");


    return 1;
}

int ft_out_error(char *mask , int len , int *pos)
{
    if(*pos == len - 1)
        return ft_error("minishell: syntax error near unexpected token `newline'");
    (*pos)++;

    while(*pos < len && mask[*pos] == 'S')
        (*pos)++;
    if(*pos < len && mask[*pos] == '>')
        return ft_error("bash: syntax error near unexpected token `>'");
    else if(*pos < len && mask[*pos] == '|')
        return ft_error("minishell: syntax error near unexpected token `|'");
    else if (*pos < len && mask[*pos] == ';')
        return ft_error("minishell: syntax error near unexpected token `;'");
    if(*pos < len && mask[*pos] == '<')
        return ft_error("minishell: syntax error near unexpected token `<'");

    (*pos)--;
    return 1;
}

int ft_append_error(char *mask , int len , int *pos)
{
    
    if(*pos == len - 1)
        return ft_error("minishell: syntax error near unexpected token `newline'");
    (*pos)++;

    while(*pos < len && mask[*pos] == 'S')
        (*pos)++;
    if(*pos < len && mask[*pos] == '|')
        return ft_error("minishell: syntax error near unexpected token `|'");
    else if (*pos < len && mask[*pos] == ';')
        return ft_error("minishell: syntax error near unexpected token `;'");
    if(*pos < len && mask[*pos] == '<' )
        return ft_error("minishell: syntax error near unexpected token `<'");
    
    return 1;
}
int ft_check_errors(char *mask, int len)
{
    int i = 0;
    while (i < len)
    {
        if(mask[i] == ';')
             if(ft_semicolon_error(mask, len , &i) == 2)
             {

                ret = 2;
                replace_ret(export);
                return 258;
             }
        if (mask[i] == 39 )
            if(ft_single_quote(mask , len , &i) == 2)
            {
                ret = 2;
                replace_ret(export);
                return 258;
            }
        if(mask[i] == 34)
            if(ft_double_quote(mask , len , &i) == 2)
            {
                 ret = 2;
                replace_ret(export);
                return 258;
            }
        if(mask[i] == '|')
        if(ft_pipe_error(mask , len , &i) == 2)
            {
                ret = 2;
                replace_ret(export);
                return 258;
            }
          if(mask[i] == '<')
        if(ft_in_error(mask , len , &i) == 2)
            {
                ret = 2;
                replace_ret(export);
                return 258;
            }
            if(mask[i] == '>'  && ((i+1 < len && mask[i+1] != '>') || (i == len -1)))
            if(ft_out_error(mask , len , &i) == 2)
            {
                ret = 2;
                replace_ret(export);
                return 258;
            }
            if(mask[i] == '>'  && i+1 < len && mask[i+1] == '>')
            {
                i++;
                if(ft_append_error(mask , len , &i) == 2)
                {
                    ret = 2;
                    replace_ret(export);
                    return 258;
                }  
            }
        
            
        i++;
    }
    return 1;
}





