#include "../header.h"

void ft_initialize()
{
    v = malloc(sizeof(t_v));
    v->p_backslash = NULL;
    v->p_sq= NULL;
    v->p_dollar= NULL;
    v->p_semicolon=NULL;
    v->p_dq = NULL;
}