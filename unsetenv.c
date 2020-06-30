#include "minishell.h"

t_enviro	*run_unsetenv(char buffer[], t_enviro *env)
{
	char	**arg;

	arg = ft_strsplit(buffer, ' ');
	if (arraylen(arg) == 2)
		ft_unsetenv(env, arg[1]);
	else
		ft_putendl("Error: What is this?");
	free(arg[0]);
	free(arg[1]);
	free(arg);
	return (env);
}

void	ft_unsetenv(t_enviro *head, char *remove)
{
	t_enviro *tmp;
	t_enviro *prev;

	tmp = head;
	if (tmp != NULL && (ft_strcmp(tmp->key, remove) == 0))
	{
		head = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp != NULL && (ft_strcmp(tmp->key, remove) != 0))
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return;
	prev->next = tmp->next;
	free(tmp);
}