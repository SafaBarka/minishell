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

int ft_sq_printable(int pos)
{
    t_sq *current = v->p_sq;
    while (current)
    {
        if(current->i == pos)
            return 1;
        current = current->next;
    }
    return 0; 
}

int ft_backslash_printable(int pos)
{
    t_backslash *current = v->p_backslash;
    while (current)
    {
        if(current->i == pos)
            return 1;
        current = current->next;
    }
    return 0; 
}

void ft_store_printable(char *s, int len)
{
      int i = 0;
      int s_q = -1;
      int d_q = -1;
      int dollar = 0;
      while ( i < len)
      { 
        if(s[i] == 34 && d_q == -1 && s_q == -1 && ft_dq_printable(i) == 0)
            d_q = i;
        else if (s[i] == 34 && d_q != -1 && s_q == -1 && ft_dq_printable(i) == 0)
            d_q = -1;
        else if (s[i] == 39 && s_q == -1 && d_q == -1 && ft_sq_printable(i) == 0)
        {
            if(i-1 >= 0)
            {
                if(s[i-1] ==  36)
                {
                    dollar = 1;
                }
            }
            s_q = i;
        }
        else if (s[i] == 39 && s_q != -1 && d_q == -1 && ft_sq_printable(i) == 0)
        {
            s_q = -1 ;
            dollar = 0;
        }
        else if (d_q != -1 && s[i] == 92 && i+1 < len)
        {
                if(s[i+1] == 36)
                {
                    ft_store_dollar(i+1); 
                    i++;
                }
                else if (s[i+1] == 39)
                {
                    ft_store_sq(i+1);
                    ft_store_backslash(i);
                    i++;
                }
                else if (s[i+1] == 92)
                {
                    ft_store_backslash(i+1);
                    i++;
                }
                else if (s[i+1] == 34 )
                {
                    ft_store_dq(i+1);
                    i++;
                }
                else if (s[i+1] == ';')
                {
                     ft_store_semicolon(i+1);
                     ft_store_backslash(i);
                     i++;
                }
                else if (s[i+1] != 36 && s[i+1] != 92 && s[i+1] != 34 &&  s[i+1] != 39)
                {
                    ft_store_backslash(i);
                    i++;
                }
        }
        else if (d_q!= -1 && s[i] != 92 && i+1 < len)
        {
                if (s[i] == 39)
                    ft_store_sq(i);
                else if (s[i] == ';')
                    ft_store_semicolon(i);
        }
        else if (s_q != -1 )
        {
               
                if(s[i] == 92 && dollar == 0)
                {
                    ft_store_backslash(i);
                }
                else if (s[i] == 92 && dollar == 1)
                {
                    if(i+1 < len)
                    {
                        if(s[i+1] == 92)
                        {
                            ft_store_backslash(i+1);
                            i++;
                        }
                        else if (s[i +1] == 39)
                        {
                            ft_store_sq(i+1);
                            i++;
                        }else if (s[i+1] == 34)
                        {
                            ft_store_dq(i+1);
                            i++;
                        }

                    }
                }
                else if (s[i] == 36 )
                    ft_store_dollar(i);
                else if (s[i] == 34 )
                    ft_store_dq(i);
                else if (s[i] == ';' )
                    ft_store_semicolon(i);
        }
        else if (d_q == -1 && s_q == -1 )
        {
            if(s[i] == 92 && i+1 < len)
            {
                if(s[i+1] ==  39)
                    ft_store_sq(i+1);
                else if (s[i+1] == 34)
                    ft_store_dq(i+1);
                else if (s[i+1] == ';')
                    ft_store_semicolon(i+1);
                else if (s[i+1] == 92)
                    ft_store_backslash(i+1);
                else if (s[i+1] == 36)
                    ft_store_dollar(i+1);
                i++;
            }
        }
        i++;
     } 
}
        
      
