#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include "get_next_line/get_next_line.h"


typedef struct s_space {
    char *split_space ;
    char *mask;
    struct s_space *next;
}t_space;

typedef struct s_redirection {
    char *split_redirection;
    char *mask;
    t_space *spaces;
    struct s_redirections *next;
}t_redirection;

typedef struct s_pipe{
    char *split_pipe;
    char *mask;
    t_redirection *redirections;
    struct s_pipe *next;
}t_pipe;

typedef struct s_semicolon{
    char *split_semicolon;
    char *mask_semicolon;
    t_space *pipes;
    struct s_semicolon *next;
}t_semicolon;

typedef struct s_var{
    t_semicolon *semicolon;
}t_var;

t_var *v;

char	*ft_strdup(const char *s1);
char *ft_create_mask(char *s, int len);
int ft_split_semicolon(char *s , char *mask , int len);
void ft_write(char *s);

void ft_print(t_semicolon *head);
void ft_store_split_semicolon(char *s, char *mask);
t_semicolon	*ft_lstlast(t_semicolon *lst);
t_semicolon	*ft_lstnew(char *split_semicolon, char *mask_semicolon);
void	ft_lstadd_back(t_semicolon **alst, t_semicolon *new);