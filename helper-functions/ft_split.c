#include "../header.h"

int ft_nbr_words(char *mask, int len,char c)
{
    int i;
    int count;

    i = 0;
    count = 0;

    count++;
    i++;
    while (i < len)
    {
        if(mask[i] == c && i + 1 < len && mask[i+1] != c)
            count++;
        i++;
    }
    return count; 
}

int ft_split(t_split **list,char *str , char *mask , int len ,char c)
{
    int count;
    int start = 0;
    int end = 0;
    char *s;
    char *m;
    int i= 0;

    count = ft_nbr_words(mask, len,c);

    while (((char *)mask)[end] && i != count)
	{
        while (((char *)mask)[end] && ((char *)mask)[end] == c)
			end++;
		start = end;
		end++;
		while (((char *)mask)[end] && ((char *)mask)[end] != c)
			end++;
		if (i < count)
        {
            if (!(s = ft_sub(str, start, (end - 1) - start + 1)))
                return 0;
            if(!(m = ft_sub(mask, start, (end - 1) - start + 1)))
                return 0;
            //remove backslash and double quote if it'is not printable
            if(c == 'S')
               ft_remove_bq(&s,&m);
            ft_store_list(list,ft_strtrim(s, " "), ft_strtrim(m,"S"), c, len);   
            i++;
        }
	}
  return 1;
}