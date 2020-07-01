#include "minishell.h"

void	ft_system(t_enviro *env, char *buffer)
{
	char	**segments;
	pid_t	pid;
	char	*str1;
	char	*str2;
	char **envp;

	envp = NULL;
	segments = ft_strsplit(buffer, ' ');
	while (env != NULL)
	{
		str1 = ft_strjoin(env->key, "=");
		str2 = ft_strjoin(str1, env->value);
		free(str1);
		envp = arraypush(envp, str2);
		free(str2);
		env = env->next;
	}

	if ((pid = fork()) == 0)
	{
		if (segments[0][0] == '/')
			execve(segments[0], segments, envp);
		else
			ft_putendl("scan_path(env, segments)");
		exit(1);
	}
	else
		wait(&pid);
	free_2d(segments);
}

// void	scan_path()