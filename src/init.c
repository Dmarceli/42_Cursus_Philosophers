#include "../incs/philo.h"

void	join_threads(t_args *args)
{
	int		i;

	i = 1;
	while (i < args->philo_n)
		while (!args->isdead)
			pthread_join(args->philo[i++], NULL);
}

int	init_mutex(t_args *args)
{
	int 	i;
	t_all	all;

	printf("\x1b[36mTIME\tPHILO #\tACTION\n\x1B[0m");
	i = -1;
	while (++i < args->philo_n)
		pthread_mutex_init(&(args->forks[i]), 0);
	i = -1;	
	while (++i < args->philo_n)
	{
		all.philo[i] = (t_philo *)malloc(sizeof(t_philo)) ;
		all.philo[i]->args = args;
		all.philo[i]->id = i + 1;
		all.philo[i]->args->isdead = 0;
		all.philo[i]->last_meal = get_curr_time();
		all.philo[i]->meals = args->times_eat;
		pthread_create(&args->philo[i] , NULL, philoact, (void *)all.philo[i]);
		usleep(100);
	}
	i = -1;	
	while (++i < args->philo_n)
		pthread_create(&args->check_death, NULL, deathchecker, (void*)all.philo[i]);
	join_threads(args);
	return (0);
}

int	init_philo(int ac, char **av)
{
	t_args *args;

	args = malloc(sizeof(t_args));
	args->print = init_print_mutex();
	args->philo_n = ft_atoi(av[1]);
	args->die_t = ft_atoi(av[2]);
	args->eat_t = ft_atoi(av[3]);
	args->sleep_t = ft_atoi(av[4]);
	args->times_eat = -1;
	args->isdead = 0;
	if (args->philo_n < 1 || args->die_t < 0 || args->eat_t < 0
	|| args->sleep_t < 0 || args->philo_n > 250)
			return (0);
	if (ac == 6)
		args->times_eat = ft_atoi(av[5]);
	if (args->philo_n == 1)
	{
		usleep(args->die_t * 1000);
		printf("%d\tPhilo\t1\tdied\n", args->die_t);
		exit(0);
	}
	init_mutex(args);
	return (1);
}