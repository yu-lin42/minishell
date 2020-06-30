#include "minishell.h"

void	read_line(char buffer[])
{
	size_t size;

	bzero(buffer, 4096);
	size = read(0, buffer, 4096);
	if (size >= 4096)
		buffer[4095] = '\0';
	buffer[size - 1] = '\0';
}

void	minishell(t_enviro *env)
{
	char buffer[4096];

	while (42)
	{
		write(1, "$>>", 3);
		read_line(buffer);
		if (ft_strlen(buffer) == 0 || buffer[0] == '\n')
			continue;
		if (ft_strncmp(buffer, "unsetenv ", 9) == 0)
			run_unsetenv(buffer, env);
		else if (strcmp(buffer, "env") == 0)
			print_list(env);
		else if (ft_strncmp(buffer, "setenv ", 7) == 0)
			run_setenv(buffer, env);
	}
}