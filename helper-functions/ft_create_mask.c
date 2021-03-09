#include "../header.h"


char *ft_create_mask(char *s, int len){
    int dq = -1;
    int sq = -1;
    int i = 0;
    int dollar = 0;

    
    char *mask = ft_strdup(s);
    if(mask == NULL)
        return NULL;
    while (i < len)
    {
        if(s[i] == 34 && dq == -1 && sq == -1 )
        {
            mask[i] = '\"';
            if(i-1 >= 0 && s[i-1] == 36)
            {
                mask[i-1] ='$';
                dollar = 1;
            }
            dq = i;
        }
        else if (s[i] == 34 && dq != -1 )
        {
            mask[i] = '\"';
            dollar = 0;
            dq = -1;
        }
        else if (s[i] == 39 && sq == -1 && dq == -1 )
        {
            mask[i] ='\'';
            if (i-1 >= 0  && s[i-1] == 36)
            {
                mask[i-1] ='$';
                dollar = 1;
            }
            sq = i;
        }
        else if (s[i] == 39 && sq != -1 )
        {
            mask[i] ='\'';
            dollar = 0;
            sq = -1;
        }
        else if (sq != -1  && dollar == 0)
        {
            if (s[i] == 92 && i+1 < len)
            {
                    
                mask[i] = 'P';
                mask[i+1] ='P';
                if(s[i+1] == 92 || s[i+1] == 36 || s[i+1] == 34 || s[i+1] ==';')
                    i++;
            }
            else if (s[i] != 92)
                mask[i] ='P';
        }
        else if (sq != -1 && dollar == 1)
        {
            if(s[i] == 92 && i+1 < len)
            {
                if(s[i+1] == 92)
                   mask[i] ='\\';
                else if (s[i+1] == 36)
                   mask[i] ='P';
                else if (s[i+1] == 39)
                   mask[i] = '\\';
                else if (s[i+1] == 34)
                    mask[i] ='\\';
                else
                    mask[i] ='P';
                mask[i+1] ='P';
                if(s[i+1] == 34 || s[i+1] == 39 || s[i+1] == 36 || s[i+1] == 92 || s[i+1] ==';')
                    i++;
            }
            else if (s[i] != 92)
                mask[i] ='P';
        }
        else if (dq != -1)
        {
            if (s[i] ==  92 && i+1 < len)
            {
                mask[i+1] = 'P';
                if(s[i+1] == 36)
                    mask[i] ='\\';
                else if (s[i+1] == 92)
                    mask[i] ='\\';
                else if(s[i+1] == 34)
                    mask[i] ='\\';
                else
                    mask[i] = 'P';
                i++;
            }
            else if (s[i] != 92)
            {
                if(s[i] == '$')
                    mask[i] = 36;
                else 
                    mask[i] = 'P';
            }
        }
        else if (dq == -1 && sq == -1)
        {
            if(s[i] == 92 && i+1 < len)
            {
                mask[i] ='\\';
                mask[i+1] ='P';
                i++;
             }else if (s[i] != 92)
             {
                 if(s[i] == ';')
                    mask[i] =';';
                else if (s[i] == '$')
                    mask[i] ='$' ;
                else if (s[i] == ' ')
                    mask[i] ='S';
                else if (s[i] == '|')
                    mask[i] ='|';
                else
                    mask[i] = 'P';
             }
    }
i++;
}
return mask;
}