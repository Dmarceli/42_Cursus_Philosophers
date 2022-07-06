#include "../incs/philo.h"

void forkpicker(t_philo *p)
{
	p->fork = p->id;
	p->fork2 = (p->id + 1) % p->args->philo_n;
}
void	pickup_fork(t_philo *philo)
{
	if (!philo->args->isdead)
	{
		isanyonedead(philo);
		forkpicker(philo);
		pthread_mutex_lock(&philo->args->forks[philo->fork]);
		pthread_mutex_lock(&philo->args->forks[philo->fork2]);
		print_states(0, get_curr_time() - philo->args->start_time, philo);
	}
}

void eat(t_philo *philo)
{
	isanyonedead(philo);
	if(philo->args->isdead == 1)
		return ;
	print_states(1, get_curr_time() - philo->args->start_time, philo);
	philo->last_meal = get_curr_time();
	usleep(philo->args->eat_t * 1000);
	philo->args->times_eat--;
	pthread_mutex_unlock(&philo->args->forks[philo->fork]);
	pthread_mutex_unlock(&philo->args->forks[philo->fork2]);
}

void	philo_sleep(t_philo *p)
{
	long long	time;
	
	isanyonedead(p);
	if(p->args->isdead == 1)
		return ;
	time = get_curr_time() - p->args->start_time;
	print_states(2, time, p);
	usleep(p->args->sleep_t * 1000);
	return ;
}


void *philoact(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while(!philo->args->isdead)
	{
		pickup_fork(philo);
		eat(philo);
		print_states(2, get_curr_time() - philo->args->start_time, philo);
		usleep(philo->args->sleep_t * 1000);
		print_states(3, get_curr_time() - philo->args->start_time, philo);
	}
	return(0);
}