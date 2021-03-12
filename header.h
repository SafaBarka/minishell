#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include "get_next_line/get_next_line.h"

typedef struct s_split {
    char *command;
    char *mask;
    struct s_split *split;
    struct s_split *next;
} t_split;

typedef struct s_var{
    t_split *semicolon;
}t_var;

// typedef struct s_space {
//     char *split_space ;
//     char *mask;
//     struct s_space *next;
// }t_space;

// typedef struct s_redirection {
//     char *split_redirection;
//     char *mask;
//     t_space *spaces;
//     struct s_redirections *next;
// }t_redirection;

// typedef struct s_pipe{
//     char *split_pipe;
//     char *mask;
//     t_redirection *redirections;
//     struct s_pipe *next;
// }t_pipe;

// typedef struct s_semicolon{
//     char *split_semicolon;
//     char *mask_semicolon;
//     t_space *pipes;
//     struct s_semicolon *next;
// }t_semicolon;

// typedef struct s_var{
//     t_semicolon *semicolon;
// }t_var;

 t_var *v;

char	*ft_strdup(const char *s1);
char *ft_create_mask(char *s, int len);
int ft_split(t_split **head, char *s , char *mask , int len ,char c);
void ft_write(char *s);

void ft_print(t_split *head);
void ft_store_split(t_split **head, char *s, char *mask);
t_split	*ft_lstlast(t_split *lst);
t_split	*ft_lstnew(char *split_semicolon, char *mask_semicolon);
void	ft_lstadd_back(t_split **alst, t_split *new);
char *ft_dollar(char *old_mask, char *line, int len);
char			*ft_strtrim(char  *s1, char  *set);
void ft_check_command(t_split **head);