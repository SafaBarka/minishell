#include "../header.h"

int	ft_strcmp(const char *s1, const char *s2)
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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i] != c)
	{
		if (str[i] != '\0')
			i++;
		else
			return (0);
	}
	return ((char *)str + i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(STDOUT_FILENO, &s[i], 1);
		i++;
	}
}

char	*ft_s(char *s, int start, size_t len)
{
	size_t	i;
	char	*src;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	src = (char *)malloc(len + 1);
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

int	ft_isalpha(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
	{
		return (0);
	}
	return (1);
}
