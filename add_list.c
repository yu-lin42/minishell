#include "minishell.h"

t_lists	*new_list(const char *stuff)
{
	t_lists	*new;

	new = (t_lists *)malloc(sizeof(t_lists));
	new->str_data = ft_strdup(stuff);
	new->next = NULL;
	return (new);
}

void	add_list(const char *stuff, t_lists *head)
{
	t_lists	*teleport;

	teleport = head;
	while (teleport->next != NULL)
		teleport = teleport->next;
	teleport->next = (t_lists *)malloc(sizeof(t_lists));
	teleport->next->str_data = ft_strdup(stuff);
	teleport->next->next = NULL;
}

t_lists		*dynamic_list(char *stuff, t_lists *head)
{
	t_lists		*teleport;

	teleport = head;
	if (head == NULL)
	{
		head = new_list(stuff);
		teleport = head;
	}
	else
	{
		add_list(stuff, teleport);
		head = teleport;
	}
	return (head);
}