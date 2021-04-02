#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include "get_next_line/get_next_line.h"
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct s_split {
    char *str;  //string
    char *mask; //mask
    int is_p;  //is_pipe
    struct s_split *split;
    struct s_split *next;
} t_split;

typedef struct s_list{
    void            *content;
    struct s_list	*next;
}               t_list;
t_list *export;
t_split *list;

void ft_write(char *s);
char *ft_create_mask(char *line, int len) ;
char *ft_dollar(char *old_mask, char *line, int len);
int ft_check_errors(char *mask, int len);
int ft_split(t_split **head, char *str , char *mask , int len ,char c);
char	*ft_sub(char  *s, int start, int len);
t_split	*ft_lstnew(char *split_semicolon, char *mask_semicolon);
int ft_store_list(t_split **list, char *str, char *mask, char c,int len);
char			*ft_strtrim(char  *s1, char  *set);
int ft_store(t_split **head, char *line, char *mask , int len);
void ft_print(t_split *head);
char			**ft_split_path(char *s, char c);
char **ft_path(char *envp[]);
void ft_exec(t_split **v, char **path);
char *ft_call_executable(char *command_name,char **split_path);
char	*ft_join(char  *s1, char  *s2);
int		ft_strncmp(char *s1,char *s2, size_t n);
int ft_exec_pipe(t_split *pipe, char **path);
char			**ft_split_path(char *s, char c);
//int ft_call(char **args)
int ft_exec_no_pipe(t_split *pi, char **path);
int ft_nbr_args(t_split *split);


/* ssghuri */

char	*ft_s(char *s, unsigned int start, size_t len);
void ft_add_export(char **p, int cw, int i);
void	ft_add_list_envp(char **envp);
void ft_deletelstsize(t_list *lst);