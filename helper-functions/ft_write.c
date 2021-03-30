#include "../header.h"

void ft_write(char *s)
{
    write(1, s, ft_strlen(s));
}