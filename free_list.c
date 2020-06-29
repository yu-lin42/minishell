#include "minishell.h"

void	free_list(t_lists *list)
{
	t_lists		*head;

	head = list;
	while (head != NULL)
	{
		free(head);
		head = head->next;
		// free(list);
		list = head;
	}
}