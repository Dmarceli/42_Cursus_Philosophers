#include "../incs/philo.h"

void start_time(t_args *philo)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	philo->start_time = time.tv_sec * 1000 - time.tv_usec / 1000;
}

long current_time(t_args *philo)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000 - time.tv_usec / 1000) - philo->start_time);
	
}