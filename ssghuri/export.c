//#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include "../header.h"



t_list	*ft_lstnews(void *content)
{
	t_list *lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_backs(t_list **alst, t_list *new)
{
	t_list *p;

	if (alst == NULL || !new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		p = *alst;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}


int		ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (s1[i] != '\0')
		return ((unsigned char)s1[i]);
	if (s2[i] != '\0')
		return ((unsigned char)s2[i] * (-1));
	return (0);
}

void sort_alpha(t_list *lst)
{
	int static counter = 0;
  t_list    *list;
  char  *tmp;
  list = lst;
  if (list)
    {
        while (list && list->next)
        {
            if (ft_strcmp(list->content, list->next->content) > 0)
            {
                tmp = list->content;
                list->content = list->next->content;
                list->next->content = tmp;
                counter = counter + 1;
                printf("swap=%d\n",counter);
            }
        list = list->next;
        }
    }
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char*)s;
	i = 0;
	while (str[i] != c)
	{
		if (str[i] != '\0')
			i++;
		else
			return (0);
	}
	return ((char*)str + i);
}

char *ft_strchr1(char *s, char c)
{
	int i = 0;
	while (s[i])
	{
		if(s[i] == c)
			return(s + i);
		i++;	
	}
	return(0);
}

int	ft_position(const char *s, int c)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = (char *)s;
	i = 0;
	k = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		if (s[i] == (char)c)
		{
			k = i;
			break;
		}
			
		i++;
	}
	
	return(k+1);
}

int	ft_position1(const char *s, int c)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = (char *)s;
	i = 0;
	k = 0;
	j = ft_strlen(s);
	while (i < j)
	{
		if (s[i] == (char)c)
		{
			k = i;
			break;
		}
			
		i++;
	}
	
	return(k);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(STDOUT_FILENO, &s[i], 1);
		i++;
	}
}

void ft_printlist(t_list *node) 
{ 
	char *s;
	char *s1;
	
  while (node) 
  { 
	  if((ft_strchr(node->content, '=')) != 0)
	  {
		ft_putstr("declare -x ");
		s1 = ft_s(node->content, 0,ft_position(node->content, '='));
		ft_putstr(s1);
		ft_putstr("\"");
		s = ft_strchr(node->content, '=');
		ft_putstr(s + 1);
		//ft_putstr(node->content);
		ft_putstr("\"\n");
	  }
	  else
	  {
		ft_putstr("declare -x ");
		ft_putstr(node->content);
		ft_putstr("\n");
	  }
	
	node = node->next; 
  } 
  //printf("%s\n", (char *)node->content);
}

t_list	*ft_lstlasts(t_list *lst)
{
	if (!lst)
		lst = (void *)0;
	else
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void ft_deletelstsize(t_list *lst)
{
	t_list *curr;

	curr = lst->next;
	while (curr->next != NULL)
	{
		lst = curr;
		curr = curr->next;
	}
	free(lst->next);
	lst->next = NULL; 
}

void freelist(t_list* head)
{
   t_list* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }
	//free(head);
}

void	ft_add_list_envp(char **envp)
{
	while(*envp)
	{
		ft_lstadd_backs(&export, ft_lstnews(ft_strdup(envp)));
		envp++;   
	}
	ft_deletelstsize(export);
    
}

int		ft_count_words(char *str, char c)
{
	int i;
	int k;
	int count;

	i = 0;
	k = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		if (*str == c)
			k = 0;
		else if (k == 0)
		{
			k = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int		ft_length(char *str, int i, char c)
{
	int len;

	len = 0;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_free(char **p, int j)
{
	while (j > 0)
	{
		j--;
		free(p[j]);
	}
	free(p);
	return (NULL);
}

// char	**ft_split(const char *s, char c)
// {
// 	char	**p;
// 	int		i;
// 	int		j;
// 	int		k;

// 	i = 0;
// 	j = 0;
// 	if (!s)
// 		return (NULL);
// 	if (!(p = malloc(sizeof(char*) * (ft_count_words((char*)s, c) + 1))))
// 		return (NULL);
// 	while (s[i] != '\0' && j < ft_count_words((char*)s, c))
// 	{
// 		k = 0;
// 		while (s[i] == c)
// 			i++;
// 		if (!(p[j] = malloc(sizeof(char) * (ft_length((char*)s, i, c) + 1))))
// 			return (ft_free(p, j));
// 		while (s[i] != c && s[i] != '\0')
// 			p[j][k++] = s[i++];
// 		p[j][k] = '\0';
// 		j++;
// 	}
// 	p[j] = 0;
// 	return (p);
// }
char	*ft_s(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*src;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	src = (char*)malloc(len + 1);
	if (src == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		src[i] = s[start];
		i++;
		start++;
	}
	src[i] = '\0';
	return (src);
}
int ft_find_env(char *s)
{
	int i = 0;
	char *s1;
	char *s2;
	char *s3;
	t_list *newlist;
	
	newlist = export;
	while(s[i])
	{
		while(newlist)
		{
			s1 = ft_s(newlist->content, 0,ft_position(newlist->content, '='));
			s2 = ft_s(newlist->content, 0,ft_position1(newlist->content, '='));
			s3 = ft_s(s, 0,ft_position1(s, '='));
			if(ft_strcmp(s, newlist->content) == 0)
				return(1);
			if(ft_strcmp(s, s2) == 0)
			{
				return(1);
			}
			else if(ft_strcmp(s, s1) == 0 || (ft_strchr(s, '=') && (ft_strcmp(s3, newlist->content) == 0  || (ft_strcmp(s3, s2) == 0 ))))
			{
				//ft_putstr("ok1");
				newlist->content = s;
				return(1);
			}
			// else if (ft_strcmp(s3, s2) == 0 && (ft_strchr(s3, '=')))//ft_strcmp(s3, s1) == 0) || 
			// {
			// 	printf("\ns2---%s--s3----%s:\n", s2,s3);
			// 	ft_putstr("ok");
			// 	newlist->content = s;
			// 	return(1);
			// }
			newlist = newlist->next;
		}
		i++;
	}
	return(0);
}

void ft_add_export(char **p, int cw, int i)
{
	//int cw = 0;
	//char **p;
    //char *line;
    //char *s = "export";
	//char *str = "env";
    // int i = 0;
	int j = 1;
	//int k = 0;
	t_list *newlist;
	
	newlist = export;
	//get_next_line(0, &line); 
	// cw = ft_count_words(line ,' ');
	// p = ft_split(line ,' ');	
		
		// i = ft_strcmp(p[0], s);
		//k = ft_strcmp(p[0], str); || (k == 0 && cw == 1)
		
        if((i == 0 && cw == 1))
        {	
			ft_printlist(newlist);
        }
		else if (i == 0 && cw > 1)
		{
			j = 1;
			while(j < cw)
			{
				if(ft_find_env(p[j]) == 1)
				{
					j++;
					continue;
					//break;
				}
					
				if(p[j][0] == 45)
				{
					ft_putstr("export: ");
					ft_putstr(p[j]);
					ft_putstr(": invalid option\n");
					break;
				}
				else if (!ft_strchr(p[j], '=') && ft_strchr(p[j], '-'))
				{
					ft_putstr("bash: export: `");
					ft_putstr(p[j]);
					ft_putstr("': not a valid identifier\n");
				}
				else if (p[j][0] == 95 && ft_strlen(p[j]) == 1)
				{
					j++;
					continue;
				}
				else if(p[j][0] == 61 || p[j][0] == 64 || p[j][0] == 58 || p[j][0] == 33)
				{
					ft_putstr("bash: export: `");
					ft_putstr(p[j]);
					ft_putstr("': not a valid identifier\n");
					//break;
				}
				
				
				else
					ft_lstadd_backs(&newlist, ft_lstnews(p[j]));
				j++;
			}	
		}
		
        // else
		// 	printf("command not found :%s\n",p[j]);    
}

void ft_sort_env(int j, int cw) 
{ 
	printf("cw = %d\n",cw);
	t_list *node;

	node = export;
	if(j == 0 && cw == 1)
	{
		while (node) 
		{ 
			if(ft_strchr(node->content, '='))
			{
				ft_putstr(node->content);
				ft_putstr("\n");
			}
			
			node = node->next; 
		} 
	}
}

void ft_del_pos(t_list **head, int pos)
{
	t_list *curr = *head;
	t_list *prev = *head;
	if(pos == 1)
	{
		*head = curr->next;
		free(curr);
		curr = NULL;
	}
	else
	{
		while(pos != 1)
		{
			prev = curr;
			curr = curr->next;
			pos--;
		}
		prev->next = curr->next;
		free(curr);
		curr = NULL;
	}
}


void ft_unset(int k, char **p, int cw)
{
	int i = 1;
	char *s;
	int j;
	t_list *head;

	if(k == 0 && cw > 1)
	{
	
		while(p[i])
		{
			head = export;
			j = 1;
			while(head)
			{
				s = ft_s(head->content, 0,ft_position1(head->content, '='));
				if(!ft_strcmp(p[i], head->content) || !ft_strcmp(p[i], s))
				{
					
					//printf("delete kada : %s \n", head->content);
					ft_del_pos(&export, j);
					break;
				}
				head = head->next;
				j++;
			}
			
			i++;
		}

	}
}

void	ft_pwd(int l, int cw)
{
	char buf[4096];

	if(l == 0 && cw == 1)
	{
		getcwd(buf, 4096);
		ft_putstr(buf);
		ft_putstr("\n");
	}
	
}

int	ft_search_home()
{
	char *s;
	t_list *head;
	head = export;

	while(head)
			{
				s = ft_s(head->content, 0,ft_position1(head->content, '='));	
				if(!ft_strcmp(s, "HOME"))
				{
					return(1);
				}
				head = head->next;	
			}
	return(0);
}

void ft_change_path(char *buf, char *path)
{
	t_list *head;
	char *s;

	head = export;
	while(head)
	{
		s = ft_s(head->content, 0,ft_position1(head->content, '='));
		if (ft_strcmp(s, "PWD") == 0)
		{
			getcwd(buf, 4096);
			head->content = ft_join("PWD=", buf);
		}
		if (!ft_strcmp(s, "OLDPWD"))
		{
			head->content = ft_join("OLDPWD=", path);
			break;
		}
		head = head->next;
	}
}

void	ft_cd(int m, int cw, char **p)
{
	char path[4096];
	char buf[4096];
	t_list *head;
	char *s;
	char *home;

	head = export;
	getcwd(path, 4096);
	if(m == 0)
	{
		if(cw == 1)
		{
			while(head)
			{
				s = ft_s(head->content, 0,ft_position1(head->content, '='));	
				if(!ft_strcmp(s, "HOME"))
				{
					int len = ft_strlen(head->content);
					home = ft_s(head->content, 5, len - 4);
					chdir(home);
					ft_change_path(buf, path);
					break;
				}
				head = head->next;	
			}
				if(!ft_search_home())
				{
					ft_putstr("bash: cd: HOME not set\n");
				}
		}	
		else
		{
			if(chdir(p[1]) == 0)
			{
				ft_change_path(buf, path);
			}
			else
			{
				ft_putstr("bash: cd: ");
				ft_putstr(p[1]);
				ft_putstr(" : No such file or directory\n");
			}
				
		}	
		
	}

}

int		ft_isalpha(int c)
{
	if ((c < 'a' || c > 'z') &&
			(c < 'A' || c > 'Z'))
	{
		return (0);
	}
	return (1);
}

int		ft_isdigit(int c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}

int		ft_atoi(const char *str)
{
	long	a;
	int		s;

	a = 0;
	s = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		s = s * (-1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (a < 0 && s > 0)
			return (-1);
		else if (s < 0 && a < 0)
			return (0);
		a = a * 10 + *str - 48;
		str++;
	}
	return (a * s);
}

void	ft_exit(int n, int cw ,char **p)
{
	int j = 0;
	if(n == 0)
	{
		if(cw == 1)
		{
			ft_putstr("exit\n");
			exit(1);
		}
		if(cw == 2 && ft_isdigit(p[1][0]))
		{
			while(p[1][j])
			{
				if(ft_isdigit(p[1][j]))
					j++;
			}
			if(j != 0)
			{
				ft_putstr("exit\n");
				exit(ft_atoi(p[1]));
			}
		}
		else if(cw >= 2)
		{
			if(!ft_isdigit(p[1][0]))
			{
				ft_putstr("exit\nbash: exit: ");
				ft_putstr(p[1]);
				ft_putstr(": numeric argument required\n");
				exit(255);
			}
			else
			{
				ft_putstr("exit\nbash: exit: too many arguments\n");
			}	
		}
	}
		
}

// int main(int argc, char *argv[], char *envp[])
// {
// 	int cw = 0;
// 	char *line;
// 	char **p;
// 	char *s[6] = {"export", "env","unset", "pwd", "cd", "exit"};
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	int l = 0;
// 	int m = 0;
//     argc = 0;
//     *argv = "test";
//     ft_putstr("*************MINISHELL*************\n");
// 	ft_add_list_envp(envp);
	
    
// 	while(1)
//     {
		
		
//         write(1,"~ ",2);
// 		get_next_line(0, &line);
// 		cw = ft_count_words(line ,' ');
// 		p = ft_split(line ,' ');
// 		i = ft_strcmp(p[0], s[0]);
// 		j = ft_strcmp(p[0], s[1]);
// 		k = ft_strcmp(p[0], s[2]);
// 		l = ft_strcmp(p[0], s[3]);
// 		m = ft_strcmp(p[0], s[4]);
// 		int n = ft_strcmp(p[0], s[5]);
// 		ft_add_export(p, cw, i);
// 		ft_sort_env(j, cw);
// 		ft_unset(k, p, cw);
// 		ft_pwd(l, cw);
// 		ft_cd(m, cw, p);
// 		ft_exit(n, cw, p);
//         // continue;
//     }
// 	//free(line);
//     //line = NULL;
// 	return(0);
// }