#include "minishell.h"

void	free_list(t_enviro *list)
{
	t_enviro		*head;

	head = list;
	while (head != NULL)
	{
		free(head);
		head = head->next;
		// free(list);
		list = head;
	}
}