#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

typedef struct s_dq{
    int i ;
    struct s_dq *next;
}t_dq;

typedef struct s_sq{
    int i ;
    struct s_sq *next;
}t_sq;

typedef struct s_backslash{
    int i ;
    struct s_backslash *next;
}t_backslash;

typedef struct s_dollar{
    int i ;
    struct s_dollar *next;
}t_dollar;

typedef struct s_semicolon{
    int i ;
    struct s_semicolon *next;
}t_semicolon;


typedef struct s_v{
    t_sq *p_sq;
    t_backslash *p_backslash;
    t_dollar *p_dollar;
    t_semicolon *p_semicolon;
    t_dq *p_dq;
}t_v;

typedef	struct		s_list{
	int			i;
	struct s_list	*next;
}					t_list;

t_v *v;

void ft_initialize();
void ft_store_printable(char *s, int len);


void ft_store_sq(int i);
t_sq	*ft_lstlast_sq(t_sq *lst);
void	ft_lstadd_back_sq(t_sq **alst, t_sq *new);
t_sq	*ft_lstnew_sq(int i);

void ft_store_semicolon(int i);
t_semicolon	*ft_lstlast_semicolon(t_semicolon *lst);
void	ft_lstadd_back_semicolon(t_semicolon **alst, t_semicolon *new);
t_semicolon	*ft_lstnew_semicolon(int i);

void ft_store_dq(int i);
t_dq	*ft_lstlast_dq(t_dq *lst);
void	ft_lstadd_back_dq(t_dq **alst, t_dq *new);
t_dq	*ft_lstnew_dq(int i);

void ft_store_dollar(int i);
t_dollar	*ft_lstlast_dollar(t_dollar *lst);
void	ft_lstadd_back_dollar(t_dollar **alst, t_dollar *new);
t_dollar	*ft_lstnew_dollar(int i);

void ft_store_backslash(int i);
t_backslash	*ft_lstlast_backslash(t_backslash *lst);
void	ft_lstadd_back_backslash(t_backslash **alst, t_backslash *new);
t_backslash	*ft_lstnew_backslash(int i);

void ft_print_backslash();
void ft_print_dollar();
void ft_print_dq();
void ft_print_semicolon();
void ft_print_sq();