/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:52 by dmarceli          #+#    #+#             */
/*   Updated: 2022/10/17 19:28:20 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	*deathchecker(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (is_run(philo->args))
	{
		if (isanyonedead(philo))
		{
			pthread_mutex_unlock(&philo->args->print);
			destroy_mutex(philo);
			break ;
		}
	}
	return (data);
}

int	isanyonedead(t_philo *philo)
{
	if (philo->args->isdead == 0)
	{
		pthread_mutex_lock(&(philo->args->last_meal_mutex));
		if ((get_curr_time() - philo->last_meal) > philo->args->die_t)
		{
			pthread_mutex_unlock(&(philo->args->last_meal_mutex));
			pthread_mutex_lock(&philo->args->print);
			if (philo->meals != 0)
				print_states(4,
					get_curr_time() - philo->args->start_time, philo);
			return (1);
		}
	}
	pthread_mutex_unlock(&(philo->args->last_meal_mutex));
	return (0);
}

int	error_message(void)
{
	printf("\x1B[31mERROR!\n\x1B[0m");
	exit(0);
	return (0);
}

void	print_states(int act, long time, t_philo *philo)
{
	if (is_run(philo->args))
	{
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
	}
}
