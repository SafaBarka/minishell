#include "../header.h"

static int		ft_start(char *s, char *set, int l)
{
	int j;
	int c;

	j = 0;
	c = 0;
	if (set[0] == '\0')
		return (0);
	while (s[c] != '\0')
	{
		j = 0;
		while (j < l)
		{
			if (s[c] != set[j] && j == l - 1)
				return (c);
			else if (s[c] != set[j])
				j++;
			else
				break ;
		}
		c++;
	}
	return (c);
}

static int		ft_end(char *s, char *set, int l, int r)
{
	int c;
	int j;

	c = l - 1;
	j = 0;
	if (set[0] == '\0')
		return (ft_strlen(s) - 1);
	while (c >= 0)
	{
		j = 0;
		while (j < r)
		{
			if (s[c] != set[j] && j == r - 1)
				return (c);
			else if (s[c] != set[j])
				j++;
			else
				break ;
		}
		c--;
	}
	return (c);
}

static char		*ft_allocation(char *str)
{
	if (!(str = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	return (str);
}

char			*ft_strtrim(char  *s1, char  *set)
{
	int		j;
	int		i;
	char	*str;
	int		start;
	int		end;

	j = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_start((char *)s1, (char *)set, ft_strlen(set));
	end = ft_end((char *)s1, (char *)set, ft_strlen(s1), ft_strlen(set));
	i = start;
	str = NULL;
	if (end < 0)
		return (ft_allocation(str));
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (i <= end)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
