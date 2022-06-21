#include "../incs/philo.h"

void forkpicker(t_philo *p)
{
	p->fork = p->id;
	p->fork2 = (p->id + 1) % p->args->philo_n;
}
void	pickup_fork(t_philo *philo)
{
	forkpicker(philo);
	pthread_mutex_lock(&philo->args->forks[philo->fork]);
	print_timestamp(0, current_time(philo->args), philo->id);
	pthread_mutex_lock(&philo->args->forks[philo->fork2]);
}

void eat(t_philo *philo)
{
	print_timestamp(1, current_time(philo->args), philo->id);
	philo->last_meal = current_time(philo->args);
	// if (philo->args->start_time - philo->last_meal
	// > (philo->args->die_t / 1000))
	// 	{
	// 		philo->args->isdead = 1;
	// 		return (0);
	// 	}
	philo->args->times_eat--;
	philo->fork = 0;
	philo->fork2 = 0;
	pthread_mutex_unlock(&philo->args->forks[philo->fork]);
	pthread_mutex_unlock(&philo->args->forks[philo->fork2]);
	//usleep(philo->args->eat_t);
	// while (current_time(philo->args) - philo->last_meal < philo->args->eat_t)
	// 	continue ;
	// return ;
}

void	philo_sleep(t_philo *p)
{
	long time;
	
	time = current_time(p->args);
	print_timestamp(2, time, p->id);
	usleep(p->args->eat_t * 1000 - 16000);
	while (current_time(p->args) - time < p->args->sleep_t)
		continue ;
	return ;
}