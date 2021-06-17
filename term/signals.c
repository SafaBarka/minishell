#include "../header.h"

void	ft_check_ret(void)
{
	while (v_fork > 0)
	{
		if (WIFSIGNALED(ret))
		{
			ft_putnbr_fd(v_fork, 1);
			ret = WTERMSIG(ret) + 128;
			ft_putnbr_fd(ret, 1);
		}
		v_fork--;
	}
}

void	handle_sigint(int sig)
{
	sig = 0;
	if (v_fork != 1)
	{
		ft_putstr("\n");
		ft_putstr("\e[1;32mSHELL-$ \e[0m");
	}
	else
		ft_putstr("\n");
	if (tab)
		tab[0] = '\0';
	ret = 1;
	replace_ret(export);
}

void	handle_sigquit(int sig)
{
	sig = 0;
	if (var == 1 && v_fork > 0)
	{
		ft_putstr("Quit: 3");
		ft_putstr("\n");
		ft_check_ret();
		replace_ret(export);
	}
}

void	ft_ctrld(void)
{
	if (!tab || ft_strlen(tab) == 0)
	{
		ft_putstr("exit");
		ft_putstr("\n");
		exit(0);
	}
}
