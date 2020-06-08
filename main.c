#include "minishell.h"

int		main(int ac, char **av)
{
	// extern char **environment;
	// t_list *local;

	// local = create_list(environment);
	// minishell(local);
	if (ac == 1)
		ft_putchar('\n');
	else if (ac == 2)
	{
		minishell(av[1]);
	}
	else
		ft_putendl("Do not go further...");
	return (0);
}