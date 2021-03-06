#include "minishell.h"

t_enviro	*run_setenv(char *buffer, t_enviro *env)
{
	char **arg;

	arg = ft_strsplit(buffer, ' ');
	if (arraylen(arg) == 2)
		ft_setenv(env, arg[1]);
	else
		ft_putendl("Error: STFU");
	free2d(arg);
	return (env);
}

void		ft_setenv(t_enviro *head, char *add)
{
	t_enviro	*tmp;
	char	**add_var;
	int check;

	check = 0;
	tmp = head;
	if (ft_strchr(add, '='))
		add_var = split_kv(add);
	else
	{
		ft_putendl("Syntax error: setenv key=value");
		return;
	}
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->key, add_var[0]) == 0)
		{
			check = 1;
			free(tmp->value);
			tmp->value = ft_strdup(add_var[1]);
			free2d(add_var);
			return;
		}
		tmp = tmp->next;
	}
	if (check == 0)
		head = dynamic_node(add, head);
	free2d(add_var);
}