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

typedef struct		s_enviro
{
	char			*key;
	char			*value;
	struct s_enviro	*next;
}					t_enviro;

char	*read_line(void);
void	minishell(t_enviro *env);

t_enviro		*dynamic_node(char *stuff, t_enviro *head);
t_enviro		*new_node(const char *stuff);
void		add_node(const char *stuff, t_enviro *head);
char	**split_kv(const char *array);
void		print_list(t_enviro *list);

size_t		arraylen(char **array);
t_enviro	*run_unsetenv(char *buffer, t_enviro *env);
void	ft_unsetenv(t_enviro *env, char *remove);
t_enviro	*run_setenv(char *buffer, t_enviro *env);
void	ft_setenv(t_enviro *head, char *add);
void	free_list(t_enviro *list);
void	free_2d(char **array);

void	ft_system(t_enviro *env, char *buffer);
char	**array_pushstr(char **array, char *str);
// size_t		arraylen(char **array);
#endif