#ifndef BUILTINS_H
# define BUILTINS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct s_pipe
{
	t_list	*output_files;
	t_list	*input_files;
	char	*command;
	int		argc;
	char	**args;
}			t_pipe;

extern char	**g_env;

int		echo(char **args, int argc, int fd);
int		pwd(int args_count);
int 	cd (char **args, int args_count);
int		unset(char **args);
int		env(int fd);
int		bash_exit(char **args, int arg);
int		export_comand(char **args, int argc, int fd);

int		is_builtin(t_pipe *command, int fd);
int		return_error(char *string, int ret);

char	*ft_strchr(const char *s, int i);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
void	ft_putendl_fd(char *s, int fd);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, char *s2, size_t n);

#endif