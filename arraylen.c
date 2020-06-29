#include "minishell.h"

size_t		arraylen(char **array)
{
	size_t i;

	i = 0;
	while(array[i] != NULL)
		i++;
	return (i);
}