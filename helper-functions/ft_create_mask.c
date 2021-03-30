#include "../header.h"

char *ft_create_mask(char *line, int len)
{
    int dq;
    int sq;
    int i;
    int dollar;
    char *mask;


    dq = -1;
    sq = -1;
    i = 0;
    dollar = 0;

    if(!(mask = ft_strdup(&line)))
        return NULL;
    while (i < len)
    {
        if(line[i] == 34 && dq == -1 && sq == -1 )
        {
            mask[i] = '\"';
            if(i-1 >= 0 && line[i-1] == 36)
            {
                mask[i-1] ='$';
                dollar = 1;
            }
            dq = i;
        }
        else if (line[i] == 34 && dq != -1 )
        {
            mask[i] = '\"';
            dollar = 0;
            dq = -1;
        }
        else if (line[i] == 39 && sq == -1 && dq == -1 )
        {
            mask[i] ='\'';
            if (i-1 >= 0  && line[i-1] == 36)
            {
                mask[i-1] ='$';
                dollar = 1;
            }
            sq = i;
        }
        else if (line[i] == 39 && sq != -1 )
        {
            mask[i] ='\'';
            dollar = 0;
            sq = -1;
        }
        else if (sq != -1  && dollar == 0)
        {
            if (line[i] == 92 && i+1 < len)
            {
                    
                mask[i] = 'P';
                mask[i+1] ='P';
                if(line[i+1] == 92 || line[i+1] == 36 || line[i+1] == 34 || line[i+1] ==';')
                    i++;
            }
            else if (line[i] != 92)
                mask[i] ='P';
        }
        else if (sq != -1 && dollar == 1)
        {
            if(line[i] == 92 && i+1 < len)
            {
                if(line[i+1] == 92)
                   mask[i] ='\\';
                else if (line[i+1] == 36)
                   mask[i] ='P';
                else if (line[i+1] == 39)
                   mask[i] = '\\';
                else if (line[i+1] == 34)
                    mask[i] ='\\';
                else
                    mask[i] ='P';
                mask[i+1] ='P';
                if(line[i+1] == 34 || line[i+1] == 39 || line[i+1] == 36 || line[i+1] == 92 || line[i+1] ==';')
                    i++;
            }
            else if (line[i] != 92)
                mask[i] ='P';
        }
        else if (dq != -1)
        {
            if (line[i] ==  92 && i+1 < len)
            {
                mask[i+1] = 'P';
                if(line[i+1] == 36)
                    mask[i] ='\\';
                else if (line[i+1] == 92)
                    mask[i] ='\\';
                else if(line[i+1] == 34)
                    mask[i] ='\\';
                else
                    mask[i] = 'P';
                i++;
            }
            else if (line[i] != 92)
            {
                if(line[i] == '$')
                    mask[i] = 36;
                else 
                    mask[i] = 'P';
            }
        }
        else if (dq == -1 && sq == -1)
        {
            if(line[i] == 92 && i+1 < len)
            {
                mask[i] ='\\';
                mask[i+1] ='P';
                i++;
             }else if (line[i] != 92)
             {
                 if(line[i] == ';')
                    mask[i] =';';
                else if (line[i] == '$')
                    mask[i] ='$' ;
                else if (line[i] == ' ')
                    mask[i] ='S';
                else if (line[i] == '|')
                    mask[i] ='|';
                else
                    mask[i] = 'P';
             }
    }
    i++;
    mask = ft_dollar(mask, line, len);
}
return mask;
}