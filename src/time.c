#include "../incs/philo.h"

void start_time(t_philo *philo)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	philo->args->start_time = time.tv_sec * 1000 - time.tv_usec / 1000;
}

long current_time(t_philo *philo)
{
	long	current;
	struct timeval time;

	gettimeofday(&time, NULL);
	current = (time.tv_sec * 1000 - time.tv_usec / 1000) - philo->args->start_time;
	printf("st = %f\n", philo->args->start_time);
	printf("ct = %ld\n", current);
	return(current);	
}