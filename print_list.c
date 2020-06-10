#include "minishell.h"

void	print_list(t_lists **list)
{
	t_lists		*head;

	head = *list;
	while (head != NULL)
	{
		ft_putendl(head->str_data);
		head = head->next;
		free(*list);
		*list = head;
	}
}