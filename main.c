#include "minishell.h"


t_enviro		*init(void)
{
	extern char **environ;
	t_enviro		*env;
	int i;

	i = 0;
	env = NULL;
	while (environ[i] != NULL)
	{
		env = dynamic_node(environ[i], env);
		i++;
	}
	return (env);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		t_enviro	*env;

		env = init();
		print_list(env);
		minishell(env);
	}
	return (0);
}