
#include "../header.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = ft_strlen(s1);
	i = 0;
	if (!(str = malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (i < j)
	{
		str[i] = 'x';
		i++;
	}
	str[i] = '\0';
	return (str);
}
