/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielsequeira <danielsequeira@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:30 by dmarceli          #+#    #+#             */
/*   Updated: 2022/10/10 22:56:26 by danielseque      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	forkpicker(t_philo *p)
{
	if (!p->args->isdead)
	{
		p->fork = p->id - 1;
		pthread_mutex_lock(&p->args->forks[p->fork]);
		p->fork2 = (p->id) % p->args->philo_n;
		pthread_mutex_lock(&p->args->forks[p->fork2]);
	}
}

void	pickup_fork(t_philo *philo)
{
	if (!philo->args->isdead)
	{
		forkpicker(philo);
		pthread_mutex_lock(&philo->args->print);
		print_states(0, get_curr_time() - philo->args->start_time, philo);
		pthread_mutex_unlock(&philo->args->print);
	}
}

void	eat(t_philo *philo)
{
	if (philo->meals != 0)
	{
		pthread_mutex_lock(&(philo->args->last_meal_mutex));
		philo->last_meal = get_curr_time();
		pthread_mutex_unlock(&(philo->args->last_meal_mutex));
		philo->meals--;
		pthread_mutex_lock(&philo->args->print);
		print_states(1, get_curr_time() - philo->args->start_time, philo);
		pthread_mutex_unlock(&philo->args->print);
		//usleep(philo->args->eat_t * 1000);
		while (philo->args->eat_t > (get_curr_time() - philo->last_meal))
		{
			if (philo->args->isdead)
				break ;
		}
		pthread_mutex_unlock(&philo->args->forks[philo->fork]);
		philo->fork = 0;
		pthread_mutex_unlock(&philo->args->forks[philo->fork2]);
		philo->fork2 = 0;
	}
}

void	philo_sleep(t_philo *p)
{
	if (p->meals != 0)
	{
		p->last_sleep = get_curr_time();
		pthread_mutex_lock(&p->args->print);
		print_states(2, (get_curr_time() - p->args->start_time), p);
		pthread_mutex_unlock(&p->args->print);
		//usleep(p->args->sleep_t * 1000);
		while (p->args->sleep_t > (get_curr_time() - p->last_sleep))
		{
			if (p->args->isdead)
				break ;
		}
		return ;
	}
}

void	*philoact(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (philo->meals != 0 && is_run(philo->args))
	{
		pickup_fork(philo);
		eat(philo);
		philo_sleep(philo);
		pthread_mutex_lock(&philo->args->print);
		print_states(3, get_curr_time() - philo->args->start_time, philo);
		pthread_mutex_unlock(&philo->args->print);
	}
	return (0);
}
