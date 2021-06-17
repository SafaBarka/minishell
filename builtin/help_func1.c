#include "../header.h"

void	ft_str_error(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(2, &s[i], 1);
		i++;
	}
}

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
	{
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
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
