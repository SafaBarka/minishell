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