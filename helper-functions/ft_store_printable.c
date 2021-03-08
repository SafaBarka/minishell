#include "../header.h"

int ft_dq_printable(int pos)
{
    t_dq *current = v->p_dq;
    while (current)
    {
        if(current->i == pos)
            return 1;
        current = current->next;
    }
    return 0; 
}

void ft_store_printable(char *s, int len){
    int dq = -1;
    int sq = -1;
    int i = 0;
    int dollar = 0;

    while (i < len){
        if(s[i] == 34 && dq == -1 && sq == -1 && ft_dq_printable(i) == 0)
        {
            if(i-1 >= 0 && s[i-1] == 36)
                dollar = 1;
            dq = i;
        }
        else if (s[i] == 34 && dq != -1 && ft_dq_printable(i) == 0)
        {
            dollar = 0;
            dq = -1;
        }
        else if (s[i] == 39 && sq == -1 && dq == -1 &&  ft_dq_printable(i) == 0)
        {
            if (i-1 >= 0  && s[i-1] == 36)
                dollar = 1;
            sq = i;
        }
        else if (s[i] == 39 && sq != -1 && ft_dq_printable(i) == 0)
        {
            dollar = 0;
            sq = -1;
        }
        else if (sq != -1  && dollar == 0) //inside single quotes , and there is no dollar before quotes
        {
            if (s[i] == 92 && i+1 < len)
            {
                    ft_store_backslash(i);
                    if(s[i+1] ==  92)
                        ft_store_backslash(i+1);
                    else if (s[i+1] == 36)
                        ft_store_dollar(i+1);
                    else if (s[i+1] == 34)
                        ft_store_dq(i+1);
                    else if (s[i+1] == ';')
                        ft_store_semicolon(i+1);
                    if(s[i+1] == 92 || s[i+1] == 36 || s[i+1] == 34 || s[i+1] ==';')
                        i++;
            }else if (s[i] != 92)
            {
                if(s[i] == ';')
                    ft_store_semicolon(i);
                else if (s[i] == 34)
                    ft_store_dq(i);
                else if (s[i] == 36)
                    ft_store_dollar(i);
            }
        }else if (sq != -1 && dollar == 1)
        {
            if(s[i] == 92 && i+1 < len)
            {
               if(s[i+1] == 92)
                   ft_store_backslash(i+1);
               else if (s[i+1] == 36)
               {
                   ft_store_backslash(i);
                   ft_store_dollar(i+1);
               }
               else if (s[i+1] == 39)
                   ft_store_sq(i+1);
                else if (s[i+1] == 34)
                    ft_store_dq(i+1);
                else if (s[i+1] == ';')
                {
                    ft_store_backslash(i);
                    ft_store_semicolon(i+1);
                }
                else 
                    ft_store_backslash(i);
                if(s[i+1] == 34 || s[i+1] == 39 || s[i+1] == 36 || s[i+1] == 92 || s[i+1] ==';')
                    i++;
            }else if (s[i] != 92)
            {
                if(s[i] == 36)
                    ft_store_dollar(i);
                else if (s[i] == ';')
                    ft_store_semicolon(i);
                else if(s[i] == 34)
                    ft_store_dq(i);
            }
        }
        else if (dq != -1)
        {
            if (s[i] ==  92 && i+1 < len)
            {
                if(s[i+1] == 36)
                {
                    ft_store_dollar(i+1);
                    i++;
                }else if (s[i+1] == 92)
                {
                    ft_store_backslash(i+1);
                    i++;
                }else if (s[i+1] == ';')
                {
                    ft_store_backslash(i);
                    ft_store_semicolon(i+1);
                    i++;
                }else if(s[i+1] == 34)
                {
                    ft_store_dq(i+1);
                    i++;
                }else if (s[i+1] == 39)
                {
                    ft_store_backslash(i);
                    ft_store_sq(i+1);
                    i++;
                }else
                    ft_store_backslash(i);
                
            }else if (s[i] != 92)
            {
                if (s[i] == ';')
                    ft_store_semicolon(i);
                else if (s[i] == 34)
                    ft_store_dq(i);
            }
        }
        else if (dq == -1 && sq == -1)
        {
            if(s[i] == 92 && i+1 < len)
            {
                if(s[i+1] == 92)
                {
                    ft_store_backslash(i+1);
                    i++;
                }else if (s[i+1] == 36)
                {
                    ft_store_backslash(i+1);
                    i++;
                }else if (s[i+1] == ';')
                {
                    ft_store_semicolon(i+1);
                    i++;
                }else if (s[i+1] == 34)
                {
                    ft_store_dq(i+1);
                    i++;
                }else if(s[i+1] == 39)
                {
                    ft_store_sq(i+1);
                    i++;
                }
        }
        i++;

    }

}}