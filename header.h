#include <stdio.h>
#include <unistd.h>
#include<sys/wait.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <termcap.h>
#include <signal.h>

# define BACKSPACE 127
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699
# define ENTER_ARROW 10
struct termios old_term;

typedef struct s_redirect {
    char *file;
    char *type;
    char *mask;
   
}               t_redirect;

typedef struct s_remove_red {
        char *before;
        char *after;
        char *join;
}               t_remove_redir;

typedef  struct s_redir{

   
    int nbr;
    int s;
    int end;
    int len ;
     char *file;
    char *mask;
}               t_redir;

typedef struct s_split {
    char *str;  //command
    char *mask; //mask
    int is_p;  //1 if there is at least one pipe
    int is_r;  //1 if there is at least one redirection
    int nbr_re;
    t_redirect *redirections;
    struct s_split *split;
    struct s_split *next;
} t_split; 

typedef struct s_mini {
    t_split *list;
    char **path;
    char **envp;
}   t_mini;

t_mini sh;

typedef struct s_dollar{
    char *maskvalue;
    char *value;
    int inside;
    char *tempm;
    char *tempc;
    char *name;
    int stop;
    int len;
    char *m;
    char *s;
}               t_dollar;
typedef struct s_fill_mask {
    int dq;
    int sq;
    int dollar;
    int len;
}           t_fill_mask;

typedef struct s_store
{
    char *str;
    char *mask;
    int count;
    int len;
    char c;
}       t_store;

typedef struct s_sub_split {
    int start ;
    int end;
    int i;
 
}       t_sub_split;

typedef struct s_sub_path{
	int start;
	int end;
	int i ;
	int cw;
}		t_sub_path;

typedef struct s_pipe {

    int nbr;
    t_split *current;
    t_split *space;
    char **args;
    char **masks;
    int nbrsplit;
    int nbrargs;
    int fd[2];
    int fd_in; 
    int fd_old;
    int pid;
    int f;
}               t_pipe;

typedef struct s_args {
    int nbrargs;
    int nbrsplit;
    int total;
    char **newargs;
    char **newmask;
    char **tmps;
    char  **tmpm;
    char *str;
    char *mask;
}           t_args;

typedef struct s_trim{
	char	*str;
	int	start;
	int end;
}				t_trim;

typedef struct s_dollar_redir {
    int len;
    int stop;
    char *name;
    char *tempc;
    char *tempm;
    char *value;
    int inside;
    
}              t_dollar_redir;
typedef struct s_npipe{
    t_split *space;

    char **args;
    char **masks;
    char *tmp;

}               t_npipe;
int is_f;
void	ft_start_dq(t_fill_mask *fill, char *line, char *mask, int *i);
void	ft_close_dq(t_fill_mask *fill, char *mask, int *i);
void	ft_start_sq(t_fill_mask *fill, char *line, char *mask, int *i);
void	ft_close_sq(t_fill_mask *fill, char *mask, int *i);
void    ft_fill_mask(t_fill_mask *fill,char *line , char *mask, int *i);
char    *ft_create_mask(char *line, int len);
int     ft_store(t_split **head, char *line, char *mask);
int     ft_split(t_split **list, t_store *store);
int     ft_store_list(t_split **list, char *str, char *mask, t_store *store);
int     ft_remove_bq(char **s, char **m);
char	**ft_split_path(char *s, char *mask, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, int start, int len);
int     ft_error(char *s);
void    ft_write(char *s);
int     ft_strlen(const char *s);
int     ft_exec_pipe(t_split *head);
void	ft_child(t_pipe *p, t_split *head);
void	ft_wait_child(t_pipe *p);
void ft_append(t_split *pipe , t_redir *infos, int i ,t_redirect *redirect);
void ft_in(t_split *pipe, t_redir *infos, int i ,t_redirect *redirect);
void ft_out(t_split *pipe, t_redir *infos, int i ,t_redirect *redirect);
int	ft_initialize_redirections(t_redir *infos,t_split *pipe,t_redirect **redirect);
int ft_end_indice(char *mask, int start,int len);
int	ft_nbr_redirections(char *mask, int len);
int	ft_check_redirection(char *mask);
int	ft_contain_redirection(char *mask);
void ft_free_double(char **argv);
int ft_contain_dollar(char *s);
char	*ft_s_exec(char *s, unsigned int start, size_t len);
//-------------------------------------------------
int	ft_ex_continue(char **p, int *j);
void	ft_sort_alpha(void);
int	ft_err(char **p, int j);
void	ft_str_error(char *s);
void	ft_dash(char **p, int j);
void ft_free_list();
int     ft_fill_args(t_pipe *p);
void	ft_builtin_cmd(char **args, t_split *current, char **masks);
char	*ft_strdup(char *s1);
char			*ft_strtrim(char  *s1,char *s2, char  *set);
char *ft_dollar(char *old_mask, char *line, int len);

int	ft_parse_line(char *line);
int ft_check_redirection(char *mask);
int ft_execute_redirections(t_redirect *redirect);
int irection(t_split *pipe);

void ft_print(t_split *head);

int ft_nbr_words(char *mask, int len,char c);
int ft_exec(t_split **v);
int		ft_strncmp(char *s1,char *s2, size_t n);
int ft_get_redirection(t_split *pipe);
int ft_exec_nopipe(t_split *pi);

int		ft_count_words(char *s, char c);
int		ft_count_words(char *s, char c);
void ft_replace_dollar(char **command, char **mask);
int ft_check_dollar(int j , t_split *current);
char **ft_path();
char    *ft_value(char *s);
char *ft_call_executable(char *command_name);
int ft_contain(char *s,char c);
int ft_call(char **args ,char **masks,t_redirect *redirections,t_split *current);
int ft_execute_builtin(char **args,t_split *current,char **masks,t_redirect *redirections);
int ft_is_builtin(char *name);
int ft_nbr_args(char **args);
int ft_echo(char **args, char **masks,int i,t_split *current);
int ft_exec_pipe(t_split *head);
int ft_nbr_space(t_split *split);
void ft_replace_dollar_exec(char **command, char **mask);
void ft_fill(char ***args, char ***masks, char *str, char *mask);
int ft_check_errors(char *mask, int len);
int ret;
typedef struct s_list{
    void            *content;
    struct s_list	*next;
}               t_list;
t_list *export;
int pressed;
int var;
int v_fork;

typedef struct		s_dlist
{
	char			*line;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_sdlist;

char		*tab;
t_sdlist	*hist;
t_sdlist	*last;
void    ft_cd(int cw, char **p);
void    ft_sort_env(int cw, char **p);
void    ft_exit(int cw ,char **p);
void    ft_add_export(char **p,char **masks, int cw, t_split *current);
char    *ft_itoa(int n);
void     ft_pwd(int cw);
void    ft_unset(char **p, int cw);
void	ft_putstr(char *s);
int     ft_check_cp(char *s);
int		ft_strcmp(const char *s1, const char *s2);
int     ft_pos(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_s(char *s, int start, size_t len);
int		ft_isdigit(int c);
void	ft_add_list_envp(char **envp);
void	ft_ctrld(void);
void	replace_ret(t_list *node);
void    handle_sigint(int sig);
void    handle_sigquit(int sig);
void	ft_init_hist();
void	delete_end(int *col);
void	ft_enter_arrow();
void	ft_up_arrow();
void	ft_remplir_tab(char *s, int *col, int c);
void	ft_lstadd_backs(t_list **alst, t_list *new);
void	ft_putnbr_fd(int n, int fd);
t_sdlist    *ft_lstlast2(t_sdlist *lst);
void        ft_lstadd_front(t_sdlist **alst, t_sdlist *new);
int         ft_lstsize(t_sdlist *lst);
t_sdlist    *ft_lstnew2(void *line);
void        ft_insertafter(t_sdlist *prev_node, char *new_data);
void        ft_ini_term();
void        ft_down_arrow(int *col);
char        *ft_itoa(int n);
int         ft_atoi(const char *str);
t_list      *ft_lstnews(void *content);
int         ft_search_home(void);
void        ft_printlist_env(void);
int         ft_f(char *s);
char	*ft_strtrim(char *s1, char *s2, char *set);

int ft_ambiguous(t_redirect *redirect , int i, char *mask);
void ft_fill_space(t_pipe *p);


void     ft_to_tab(t_list *export);
int     ft_nbr_elemnts(t_list *export);
char **array_export(void);
char	*gat_var(char *p, char *var);
void	ft_free_tmp(char *var, char *p);
void ft_p();

typedef struct s_arr {
        int n;
        int j;
        int i;
        int k;
        char *s;
        t_list *newlist;
}               t_arr;

char * ft_write_string(char *args, char *message,int i);
char *ft_path_no_slash(char *args);
char *ft_free1(char  *path, char *join);
char *ft_free2(char *path, char *join);
char *ft_free3(int i, int ret, char *join, char *args);