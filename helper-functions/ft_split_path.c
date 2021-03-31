#include "../header.h"
static char		**free_tab(int i, char **str)
{
	while (--i >= 0)
	{
		free(str[i]);
	}
	free(str);
	return (NULL);
}

static char		**result(int i, int cw, char **str)
{
	if (i == cw)
		str[i] = NULL;
	return (str);
}
static int		count_words(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (s == NULL || !s[i])
		return (0);
	while (s[i] == c)
		i++;
	if (s[i])
	{
		count++;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char			**ft_split_path(char *s, char c)
{
	int		start;
	int		end;
	int		i;
	int		cw;
	char	**str;

	start = 0;
	end = 0;
	i = 0;
	cw = count_words((char *)s, c);
	if (s == NULL || !(str = (char **)malloc(sizeof(char *) * (cw + 1))))
		return (NULL);
	while (((char *)s)[end] && i != cw)
	{
		while (((char *)s)[end] && ((char *)s)[end] == c)
			end++;
		start = end;
		end++;
		while (((char *)s)[end] && ((char *)s)[end] != c)
			end++;
		if (i < cw)
			if (!(str[i++] = ft_sub(s, start, (end - 1) - start + 1)))
				return (free_tab(i, str));
	}
	return (result(i, cw, str));
}