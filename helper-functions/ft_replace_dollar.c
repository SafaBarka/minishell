#include "../header.h"

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
            //s = ft_s(export, 0,ft_position1(export, '='));
            printf("name = %s\n",name);
            tempc = *command;
            tempm = *mask;

            *command = ft_join(ft_su(tempc,0,i) ,"Y");
            *command = ft_join(*command , ft_su(tempc,stop,(len-1) - stop +1));

            *mask = ft_join(ft_su(tempm,0,i) ,"Y");
            *mask = ft_join(*mask , ft_su(tempm,stop,(len-1) - stop +1));
            len = ft_strlen(*mask);
        //break;
        }
        i++;
    }
    printf("command = |%s|\n",*command);

}