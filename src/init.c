#include "../incs/philo.h"

void *philoact(void *data)
{
	t_philo	*philo;
	t_args	args;


	philo = (t_philo *)data;
	forkpicker(philo);
	while(!args.isdead)
	{
		pthread_mutex_lock(&philo->args->forks[philo->fork]);
		current_time(philo);
		//print_timestamp(0, current_time(philo), philo->id);
		pthread_mutex_lock(&philo->args->forks[philo->fork2]);
	}
	return (NULL);
}

int	init_mutex(t_args *args)
{
	int 	i;
	t_all	all;

	i = -1;
	while (++i < args->philo_n)
		pthread_mutex_init(&(args->forks[i]), 0);
	i = -1;
	while (++i < args->philo_n)
	{
		all.philo[i] = (t_philo *)malloc(sizeof(t_philo)) ;
		all.philo[i]->args = args;
		all.philo[i]->id = i;
		all.philo[i]->meals = 0;
		pthread_create(&args->philo[i] , NULL, philoact, (void *)all.philo[i]);
		usleep(150);
	}
	return (0);
}
int	init_philo(int ac, char **av)
{
	t_args *args;

	args = malloc(sizeof(t_args));
	args->philo_n = ft_atoi(av[1]);
	args->die_t = ft_atoi(av[2]);
	args->eat_t = ft_atoi(av[3]);
	args->sleep_t = ft_atoi(av[4]);
	args->times_eat = 0;
	args->isdead = 0;
	if (args->philo_n < 1 || args->die_t < 0 || args->eat_t < 0
	|| args->sleep_t < 0 || args->philo_n > 250)
			return (0);
	if (ac == 6)
		args->times_eat = ft_atoi(av[5]);
	init_mutex(args);
	return(1);
}