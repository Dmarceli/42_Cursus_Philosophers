/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielsequeira <danielsequeira@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:55 by dmarceli          #+#    #+#             */
/*   Updated: 2022/10/14 03:09:03 by danielseque      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	destroy_mutex(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->is_run_mutex);
	philo->args->is_run = 0;
	pthread_mutex_unlock(&philo->args->is_run_mutex);
}

int	is_run(t_args *args)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&args->is_run_mutex);
	i = args->is_run;
	pthread_mutex_unlock(&args->is_run_mutex);
	return (i);
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
