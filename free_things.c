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

void	free_2d(char **array)
{
	int		i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}