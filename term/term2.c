#include "../header.h"

void	ft_up_arrow(int *col)
{
	if (last && last->prev)
	{
		pressed = 1;
		ft_putstr("\r");
		ft_write("\e[1;32mSHELL-$ \e[0m");
		write(1, tgetstr("ce", NULL), ft_strlen(tgetstr("ce", NULL)));
		last = last->prev;
		ft_putstr(last->line);
		tab = ft_strdup(last->line);
		*col = ft_strlen(tab);
	}
}

void	ft_down_arrow(int *col)
{
	if (last && last->next)
	{
		ft_putstr("\r");
		ft_write("\e[1;32mSHELL-$ \e[0m");
		write(1, tgetstr("ce", NULL), ft_strlen(tgetstr("ce", NULL)));
		last = last->next;
		ft_putstr(last->line);
		tab = ft_strdup(last->line);
		*col = ft_strlen(tab);
	}
}

void	ft_init_hist(void)
{
	pressed = 0;
	ft_ini_term();
	tab = ft_strdup("");
	if (ft_lstsize(hist) == 0)
	{
		hist = ft_lstnew2("");
		hist->prev = NULL;
	}
	last = ft_lstlast2(hist);
}

void	ft_remplir_tab(char *s, int *col, int c)
{
	char	*free_tmp;

	(*col)++;
	if (c >= 32 && c <= 126)
	{
		write(0, &c, 1);
		s = (char *)malloc(sizeof(*s) * 2);
		s[0] = c;
		s[1] = '\0';
		free_tmp = tab;
		tab = ft_strjoin(tab, s);
		free(free_tmp);
		if (pressed == 1)
		{
			last->line = ft_strdup(tab);
		}
	}
	free(s);
}
