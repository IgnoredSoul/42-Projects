#include "ft_printf/ft_printf.h"

void	send_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = -1;
	while (++i <= len)
	{
		shift = 0;
		while (shift < 7)
		{
			if ((str[i] >> shift++) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
		}
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		return (ft_printf("Must Contain ONE Word!"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_bit(pid, str, ft_strlen(str));
}
