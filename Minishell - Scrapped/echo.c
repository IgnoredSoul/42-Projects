#include "builtins.h"

int	echo(char **args, int argc, int fd)
{
	int	i;

	i = 0;
	if (argc == 0)
	{
		write('\n', fd);
		return (0);
	}

	while (args[i] && !ft_strcmp(args[i], "-n"))
		i++;

	while (i < argc - 1)
	{
		write(args[i++], fd);
		write(" ", fd);
	}

	if (i != argc)
		write(args[i], fd);

	if (ft_strcmp(args[0], "-n"))
		write("\n", fd);
		
	return (0);
}