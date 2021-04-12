#include "../header.h"

void ft_echo(char **args)
{
    int i = 0;
    int j;
    int len;
    while (args[i])
    {   j = 0;
        len = ft_strlen(args[i]);
        while(j < len)
        {
            write(1,&args[i][j],1);
            j++;
        }

       
        i++;
        if(args[i] != NULL)
             write(1," ",1);
    }
    write(1,"\n",1);
}