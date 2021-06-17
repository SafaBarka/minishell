#include "../header.h"

void	ft_ini_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	old_term = term;
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	tgetent(NULL, getenv("TERM"));
}

void	delete_end(int *col)
{
	if (ft_strlen(tab) > 0)
	{
		if (*col > 0)
		{
			--(*col);
			write(1, tgetstr("le", NULL), ft_strlen(tgetstr("le", NULL)));
			write(1, tgetstr("ce", NULL), ft_strlen(tgetstr("ce", NULL)));
			tab[ft_strlen(tab) - 1] = '\0';
		}
	}
}

void	ft_printlist_hist(t_sdlist *node)
{
	while (node != NULL)
	{
		ft_putstr("------\n");
		ft_putstr("Prev : ");
		if (node->prev)
			ft_putstr(node->prev->line);
		ft_putstr(" | ");
		ft_putstr("line : ");
		ft_putstr(node->line);
		ft_putstr(" | Next : ");
		if (node->next)
			ft_putstr(node->next->line);
		ft_putstr("\n");
		node = node->next;
	}
}

void	ft_enter_arrow(void)
{
	if (ft_lstsize(hist) == 1)
	{
		if (tab[0] != '\0')
		{
			ft_lstadd_front(&hist, ft_lstnew2(ft_strdup(tab)));
			hist->prev = NULL;
			ft_lstlast2(hist)->prev = hist;
		}
	}
	else if (ft_lstsize(hist) > 1)
	{
		if (tab[0] != '\0')
			ft_insertafter(ft_lstlast2(hist)->prev, tab);
	}
	ft_lstlast2(hist)->line = "";
	last = ft_lstlast2(hist);
	ft_putstr("\n");
	pressed = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
}
