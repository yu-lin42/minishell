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

typedef struct		s_lists
{
	char			*str_data;
	struct s_lists	*next;
}					t_lists;

void		minishell(char *cmd);
void		get_env(char **env);
t_lists		*dynamic_list(char *stuff, t_lists *head);
t_lists		*new_list(const char *stuff);
void		add_list(const char *stuff, t_lists *head);
void		print_list(t_lists **list);
#endif