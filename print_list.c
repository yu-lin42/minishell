#include "minishell.h"

void	print_list(t_enviro *list)
{
	t_enviro		*head;

	head = list;
	while (head != NULL)
	{
		ft_putstr(head->key);
		ft_putchar('=');
		ft_putendl(head->value);
		head = head->next;
		list = head;
	}
}