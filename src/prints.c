#include "../incs/philo.h"

void *deathchecker(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (!philo->args->isdead)
	{
		if(isanyonedead(philo))
		{
			exit(0);
		}
	}
	exit(0);

}


int	isanyonedead(t_philo *philo)
{
	if (philo->args->isdead == 0)
	{
		if ((get_curr_time() - philo->last_meal) > philo->args->die_t)
		{
			philo->args->isdead = 1;
			print_states(4, get_curr_time() - philo->args->start_time, philo);
			//pthread_mutex_lock(philo->args->print);
			destroy_mutex(philo);
			exit(0);
			return (1);
		}
	}
	return (0);
}

pthread_mutex_t	*init_print_mutex(void)
{
	pthread_mutex_t	*printer_mutex;

	printer_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(printer_mutex, NULL);
	return (printer_mutex);
}

int	error_message(void)
{
	printf("\x1B[31mERROR!\n\x1B[0m");
	exit(0);
	return (0);
}
void	print_states(int act, long time, t_philo *philo)
{
	{
		pthread_mutex_lock(philo->args->print);
		if (act == 0)
		{
			printf("%ldms\tphilo %d has taken a fork\n", time, philo->id);
			printf("%ldms\tphilo %d has taken a fork\n", time, philo->id);
		}
		else if (act == 1)
			printf("%ldms\tphilo %d is eating\n", time, philo->id);
		else if (act == 2)
			printf("%ldms\tphilo %d is sleeping\n", time, philo->id);
		else if (act == 3)
			printf("%ldms\tphilo %d is thinking\n", time, philo->id);
		else if (act == 4)
			printf("%ldms\tphilo %d died\n", time, philo->id);
		pthread_mutex_unlock(philo->args->print);
	}
}