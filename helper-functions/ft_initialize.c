#include "../header.h"

int ft_initialize()
{
    if(!(v = malloc(sizeof(t_var))))
        return 0;
    v->p_backslash = NULL;
    v->p_dollar = NULL;
    v->p_dq = NULL;
    v->p_sq = NULL;
    v->p_semicolon = NULL;
    return 1;
}