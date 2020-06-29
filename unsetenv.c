#include "minishell.h"

t_enviro	*run_unsetenv(char buffer[], t_enviro *env)
{
	char	**arg;

	arg = ft_strsplit(buffer, ' ');
	// ft_putnbr(arraylen(arg));
	ft_putchar('\n');
	if (arraylen(arg) == 2)
		ft_unsetenv(env, arg[1]);
	else
		ft_putendl("Error: What is this?");
	return (env);
}

void	ft_unsetenv(t_enviro *env, char *remove)
{
	int check;

	check = 0;
	while (env != NULL)
	{
		if (ft_strcmp(env->key, remove) == 0)
		{
			check = 1;
			free(env->key);
			free(env->value);
		}
		env = env->next;
	}
	if (check == 0)
		ft_putendl("Error: Non-existence");
}