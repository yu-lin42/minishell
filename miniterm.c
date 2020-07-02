#include "minishell.h"

void	replace_tab(char buffer[])
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\t')
			buffer[i] = ' ';
		i++;
	}
}

char	*read_line(void)
{
	size_t size;
	char	*str;
	char	buffer[4096];

	bzero(buffer, 4096);
	size = read(0, buffer, 4096);
	if (size >= 4096)
		buffer[4095] = '\0';
	buffer[size - 1] = '\0';
	replace_tab(buffer);
	str = ft_strtrim(buffer);
	return (str);
}

void	minishell(t_enviro *env)
{
	char *buffer;

	while (42)
	{
		write(1, "$>", 2);
		buffer = read_line();
		if (ft_strlen(buffer) == 0 || buffer[0] == '\n')
			continue;
		if (ft_strncmp(buffer, "unsetenv ", 9) == 0)
			run_unsetenv(buffer, env);
		else if (strcmp(buffer, "env") == 0)
			print_list(env);
		else if (ft_strncmp(buffer, "setenv ", 7) == 0)
			run_setenv(buffer, env);
		else if (ft_strcmp(buffer, "exit") == 0)
			{
				free_list(env);
				return;
			}
		else if (ft_strncmp(buffer, "cd ", 3) == 0 || ft_strcmp(buffer, "cd") == 0)
			env = ft_cd(env, buffer);
		else
			ft_system(env, buffer);
		free(buffer);
	}
}