#include "minishell.h"

void	minishell(char *cmd)
{
	extern char **environ;

	if (ft_strcmp(cmd, "echo") == 0)
		ft_putendl("print something");
	else if (ft_strcmp(cmd, "cd") == 0)
		ft_putendl("change directory");
	else if (ft_strcmp(cmd, "env") == 0)
		get_env(environ);
	else if (ft_strcmp(cmd, "setenv") == 0)
		ft_putendl("set enviroment things");
	else if (ft_strcmp(cmd, "unsetenv") == 0)
		ft_putendl("unset environment things");
	else if (ft_strcmp(cmd, "exit") == 0)
		ft_putendl("BYEEE!");
	else
		ft_putendl("Scan for other commands");
}