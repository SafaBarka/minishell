#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_split {
    char *command;
    char *mask;
    int pipe;
    int space;
    int semicolon;
    struct s_split *split;
    struct s_split *next;
} t_split;

typedef struct s_var{
    t_split *semicolon;
}t_var;
t_var *v;

char	*ft_strdup(const char *s1);
char *ft_create_mask(char *s, int len);
int ft_split(t_split **head, char *s , char *mask , int len ,char c);
void ft_write(char *s);

void ft_print(t_split *head);
void ft_store_split(t_split **head, char *s, char *mask,char c, int len);
t_split	*ft_lstlast(t_split *lst);
t_split	*ft_lstnew(char *split_semicolon, char *mask_semicolon);
void	ft_lstadd_back(t_split **alst, t_split *new);
char *ft_dollar(char *old_mask, char *line, int len);
char *ft_strtrim(char  *s1, char  *set);
int ft_store_list(t_split **head, char *line, char *mask , int len);
char			**ft_split_path(char *s, char c);

char *ft_find_path(char *envp[]);
int		ft_strncmp(char *s1,char *s2, size_t n);