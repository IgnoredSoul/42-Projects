#include "../../includes/philosophers.h"

int	check_last_meal(t_philo *philo)
{
	if (get_time() - philo->general->starting_time > philo->time_to_die)
	{
		philo->general->philosopher_dead = 1;
		printf("%d %d died\n", get_time() - philo->general->starting_time, philo->id);

		return (0);
	}
	else
		return (1);
}

int	check_if_one_is_dead(t_general *general)
{
	int	i;

	i = 0;

	while (i < general->number_of_philosophers)
	{
		if (check_last_meal(&general->philosophers[i]) == ERROR)
			return (ERROR);

		i++;
	}

	return (1);
}

void	free_philosophers(t_general *philosophers)
{
	free(philosophers->philosophers);
	free(philosophers->fork_mutex);
}

void	*begin_monitoring(void *arg)
{
	t_general	*data;

	data = (t_general *)arg;

	while (1)
	{
		pthread_mutex_lock(&data->mutex);

		if (check_if_one_is_dead(data) == ERROR)
		{
			usleep(100);
			return (pthread_mutex_unlock(&data->mutex), NULL);
		}

		pthread_mutex_unlock(&data->mutex);
		usleep(200);
	}
}
