#include "ft_printf/ft_printf.h"

void	bit_handler(int bit)
{
	int	i;

	i = 0;
	g_msg.c += ((bit & 1) << g_msg.i++);
	if (g_msg.i != 7)
		return (0);
	ft_printf("%c", g_msg.c);
	if (!g_msg.c)
		ft_printf("\n");
	g_msg.c = 0;
	g_msg.i = 0;
}

int	main(void)
{
	ft_printf("Server Has Started!\nMy Server PID Is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_handler);
		signal(SIGUSR1, bit_handler);
		pause();
	}
	return (0);
}
