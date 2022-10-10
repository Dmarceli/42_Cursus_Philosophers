/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:42 by dmarceli          #+#    #+#             */
/*   Updated: 2022/10/10 22:04:14 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/philo.h"

void	join_threads(t_args *args)
{
	int		i;

    i = -1;
	while (++i < args->philo_n)
		pthread_join((args->check_death[i]), NULL);
	i = -1;
	while (++i < args->philo_n)
		pthread_join(args->philo[i], NULL);
	pthread_mutex_destroy(&args->print);
	exit(0);
}

int	init_mutex(t_args *args)
{
	int		i;

	printf("\x1b[36mTIME\tPHILO #\tACTION\n\x1B[0m");
	i = -1;
	while (++i < args->philo_n)
		pthread_mutex_init(&args->forks[i], 0);
	pthread_mutex_init(&(args->last_meal_mutex), NULL);
	i = -1;
	while (++i < args->philo_n)
	{
		//all.philo[i] = (t_philo *)malloc(sizeof(t_philo));
		args->philos[i].args = args;
		args->philos[i].id = i + 1;
		args->philos[i].last_meal = get_curr_time();
		args->philos[i].meals = args->times_eat;
		pthread_create(&args->philo[i], NULL, philoact, &args->philos[i]);
		usleep(150);
	}
	i = -1;
	while (++i < args->philo_n)
		pthread_create(&args->check_death[i], NULL, deathchecker,
			(void *)  &args->philos[i]);
	join_threads(args);
	return (0);
}

int	init_philo(int ac, char **av)
{
	static t_args	args;

	pthread_mutex_init(&args.print, NULL);
	pthread_mutex_init(&args.is_run_mutex, NULL);
	args.is_run = 1;	
	args.philo_n = ft_atoi(av[1]);
	args.die_t = ft_atoi(av[2]);
	args.eat_t = ft_atoi(av[3]);
	args.sleep_t = ft_atoi(av[4]);
	args.times_eat = -1;
	args.start_time = get_curr_time();
	args.isdead = 0;
	if (args.philo_n < 1 || args.die_t < 0 || args.eat_t < 0
		|| args.sleep_t < 0 || args.philo_n > 250)
		return (0);
	if (ac == 6)
		args.times_eat = ft_atoi(av[5]);
	if (args.philo_n == 1)
	{	
		usleep(args.die_t * 1000);
		printf("%d\tPhilo\t1\tdied\n", args.die_t);
		exit(0);
	}
	init_mutex(&args);
	return (1);
}
