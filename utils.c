#include "minishell.h"

char	**array_pushstr(char **array, char *str)
{
	char **new;
	size_t i;

	i = 0;
	if (array == NULL)
	{
		new = (char **)malloc(sizeof(char*) * 2);
		new[0] = ft_strdup(str);
		new[1] = NULL;
	}
	else
	{
		new = (char **)malloc(sizeof(char *) * (arraylen(array) + 2));
		while (array[i])
		{
			new[i] = ft_strdup(array[i]);
			i++;
		}
		new[i] = ft_strdup(str);
		new[++i] = NULL;
		free_2d(array);
	}
	return (new);
}