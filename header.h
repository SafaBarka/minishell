#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

typedef struct s_indice{
    int i ;
    struct s_indice *next;
}t_indice;


typedef struct s_var{
    t_indice *p_backslash;
    t_indice *p_dq;
    t_indice *p_sq;
    t_indice *p_semicolon;
    t_indice *p_dollar;
}t_var;


// typedef struct s_redirection{
//     char *split_
// }t_redirection;
// typedef struct s_split{
//     char *split_semicolon;

// }t_element;

t_var *v ;

int ft_initialize();
t_indice	*ft_lstlast(t_indice *lst);
t_indice	*ft_lstnew(int i);
void	ft_lstadd_back(t_indice **alst, t_indice *new);
void ft_print(t_indice *head);

void ft_store_backslash(int i);
void ft_store_dollar(int i);
void ft_store_dq(int i);
void ft_store_semicolon( int i);
void ft_store_sq(int i);
char	*ft_strdup(const char *s1);
char *ft_store_printable(char *s, int len);