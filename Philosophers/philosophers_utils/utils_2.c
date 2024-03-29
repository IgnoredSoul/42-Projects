#include "../philosophers.h"

void	print_message(char *str, t_philo *philosopher)
{
	if (!philosopher_is_dead(philosopher))
	{
		pthread_mutex_lock(&philosopher->general->mutex);
		printf("%d %d %s\n", get_time() - philosopher->general->starting_time, philosopher->id, str);
		pthread_mutex_unlock(&philosopher->general->mutex);
	}
}

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);

	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_sleep(int time, t_philo *philosophers)
{
	int	start;

	start = get_time();

	while ((get_time() - start) < time && philosopher_is_dead(philosophers) == FALSE)
		usleep(50);
}
