#include "builtins.h"

int	pwd(int args_count)
{
	char	*cwd;
	int		error_temporary;

	if (args_count == 0)
	{
		cwd = getcwd(NULL, 4096);
		if (cwd == NULL)
		{
			error_temporary = errno;
			write("pwd: ", 2);
			write(strerror(error_temporary), 2);
			write("\n", 2);
		}
		else
		{
			printf("%s\n", cwd);
			free(cwd);
		}
	}
	else
		write("pwd: too many arguments\n", 2);
		
	return (0);
}