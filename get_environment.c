#include "minishell.h"

void	get_env(char **env)
{
	t_lists		*en;
	int i;

	i = 0;
	en = NULL;
	while (env[i] != NULL)
	{
		en = dynamic_list(env[i], en);
		i++;
	}
	print_list(&en);
}