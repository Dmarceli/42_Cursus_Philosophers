/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:55 by dmarceli          #+#    #+#             */
/*   Updated: 2022/10/10 22:03:56 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	destroy_mutex(t_philo *philo)
{
	/*int	x;

	x = 0;*/
	pthread_mutex_lock(&philo->args->is_run_mutex);
	philo->args->is_run = 0;
	pthread_mutex_unlock(&philo->args->is_run_mutex);
	/*while (x < philo->args->philo_n)
	{
		if(philo->id == (x + 1))
			continue;
		pthread_mutex_destroy(&philo->args->forks[x]);
		pthread_detach(philo->args->philo[x]);
		pthread_detach(philo->args->check_death[x]);
		printf("destroy_mutex\n");
		x++;
	}
	x = philo->id + 1;
	pthread_mutex_destroy(&philo->args->forks[x]);
	pthread_detach(philo->args->philo[x]);
	pthread_detach(philo->args->check_death[x]);
	exit(0);*/
}

int is_run(t_args *args)
{
	int i;

	i = 0;
	pthread_mutex_lock(&args->is_run_mutex);
	i = args->is_run;
	pthread_mutex_unlock(&args->is_run_mutex);
	return i;
}

long long	get_curr_time(void)
{
	struct timeval	time;
	long long		usec;
	long long		sec;
	long long		msec;

	gettimeofday(&time, NULL);
	usec = (time.tv_usec / 1000);
	sec = (time.tv_sec * 1000);
	msec = sec + usec;
	return (msec);
}
