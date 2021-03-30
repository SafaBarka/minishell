#include "../header.h"

char	*ft_sub(char  *s, int start, int len)
{
	char	*str;
	int	i;
	int	j;

	j = 0;
	str = NULL;
	if (s == NULL)
		return (NULL);
	else if (start >= ft_strlen((char *)s))
		len = 0;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	else
	{
		i = (size_t)start;
		while (i < (len + start))
		{
			str[j] = ((char*)s)[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}