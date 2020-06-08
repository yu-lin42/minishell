#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <stdlib.h>

// typedef struct	s_list
// {
// 	char	*data;
// 	struct s_list	*next;
// }					t_list;

void	minishell(char *cmd);

#endif