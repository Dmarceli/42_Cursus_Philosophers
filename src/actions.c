#include "../incs/philo.h"

void	forkpicker(t_philo *p)
{
		if (!p->args->isdead)
		{
			p->fork = p->id;
			p->fork2 = (p->id + 1) % p->args->philo_n;
		}
}

void	pickup_fork(t_philo *philo)
{
	if (!philo->args->isdead)
	{
		forkpicker(philo);
		pthread_mutex_lock(&philo->args->forks[philo->fork]);
		pthread_mutex_lock(&philo->args->forks[philo->fork2]);
		print_states(0, get_curr_time() - philo->args->start_time, philo);
	}
}

void	eat(t_philo *philo)
{
	if (philo->meals != 0 && !philo->args->isdead)
	{
		print_states(1, get_curr_time() - philo->args->start_time, philo);	
		philo->last_meal = get_curr_time();
		while (philo->args->eat_t > (get_curr_time() - philo->last_meal))
		{
			isanyonedead(philo);
			if(philo->args->isdead)
				break ;
		}
		philo->meals--;
		if (!philo->args->isdead)
		{
			pthread_mutex_unlock(&philo->args->forks[philo->fork]);
			philo->fork = 0;
			pthread_mutex_unlock(&philo->args->forks[philo->fork2]);
			philo->fork2 = 0;
		}
	}
}

void	philo_sleep(t_philo *p)
{
	if (!p->args->isdead && p->meals != 0)
	{
		print_states(2, (get_curr_time() - p->args->start_time), p);
		p->last_sleep = get_curr_time();
		while (p->args->sleep_t > (get_curr_time() - p->last_sleep))
		{
			isanyonedead(p);
			if(p->args->isdead)
				break ;
		}
		return ;
	}
}


void *philoact(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	philo->args->start_time = get_curr_time();
	while(!philo->args->isdead && philo->meals != 0)
	{
		if (!isanyonedead(philo) && !philo->args->isdead)
			pickup_fork(philo);
		if (!isanyonedead(philo) && !philo->args->isdead)
			eat(philo);
		if (!isanyonedead(philo) && !philo->args->isdead)
			philo_sleep(philo);
		if (!isanyonedead(philo) && !philo->args->isdead)
			print_states(3, get_curr_time() - philo->args->start_time, philo);
	}
	return(0);
}