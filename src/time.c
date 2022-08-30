/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:55 by dmarceli          #+#    #+#             */
/*   Updated: 2022/08/30 16:18:15 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	destroy_mutex(t_philo *philo)
{
	int	x;

	x = 0;
	while (x < philo->args->philo_n)
	{
		pthread_mutex_destroy((philo->args->forks));
		x++;
	}
	pthread_mutex_destroy((philo->args->print));
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
