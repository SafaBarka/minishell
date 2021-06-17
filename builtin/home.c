#include "../header.h"

int	ft_search_home(void)
{
	char	*s;
	t_list	*head;

	head = export;
	while (head)
	{
		s = ft_s(head->content, 0, ft_pos(head->content, '='));
		if (!ft_strcmp(s, "HOME"))
		{
			free(s);
			return (1);
		}
		head = head->next;
		free(s);
	}
	return (0);
}
