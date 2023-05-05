#include "builtins.h"

int	env(int fd)
{
	int	i;

	i = 0;
	while (g_env[i++])
	{
		if (g_env[i][0] != '?' && g_env[i][0] != '-')
		{
			write(g_env[i], fd);
			write("\n", fd);
		}
	}

	return (0);
}