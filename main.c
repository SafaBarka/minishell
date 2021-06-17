#include "header.h"

int main(int argc , char *argv[] , char *envp[])
{ 
    //char *line;
    int c;
	int col;
	char *s = NULL;
    char *line = NULL;

    ft_add_list_envp(envp);
    sh.path =  ft_path();
    //ft_to_tab(export);
    //sh.envp = array_export();
    
    //--to delete--
    if (argc == 3)
    {
        tab = argv[2];
        line = ft_strdup(tab);
        ft_parse_line(line);
            return ret;  
    }
    //----------------

    else
    {
        signal(SIGINT, handle_sigint);
        signal(SIGQUIT, handle_sigquit);
        ft_write("\e[1;31m***********************\e[0m\n");
        ft_write("\e[1;31m         SHELL         \e[0m\n");
        ft_write("\e[1;31m***********************\e[0m\n\n\n");
        while(1)
        {
            c = 0;
            ft_write("\e[1;32mSHELL-$ \e[0m");
            ft_init_hist();
            col = 0;
            v_fork = 0;
          
            while(read(STDIN_FILENO,&c, sizeof(c)) > 0)
            {
                if (c == BACKSPACE) 
                    delete_end(&col);
          
                else if(c == ENTER_ARROW)
                {
                    
                    ft_enter_arrow();
                    line = ft_strdup(tab);
                    //printf("line = |%p|\n",line);
                    ft_parse_line(line);
                    //free(line);
                   // if(tab[0] == '\0')
                     //   free(tab);
                    break;
                }
                else if (c == UP_ARROW)
                    ft_up_arrow(&col);
                else if (c == DOWN_ARROW)
                    ft_down_arrow(&col);
                else if (c == 4)
                   ft_ctrld();
                else
                {
                    ft_remplir_tab(s, &col, c); 
                }
                c = 0;
            }
           // printf("tab = |%p|\n",tab);
            free(tab);
        }
    }
}