#include "../incs/philo.h"


int	init_mutex(t_args *args)
{
	int i;

	i = 0;
	while (++i >= args->philo_n)
	{
		if (pthread_mutex_init(&(args->forks[i]), 0))
			return (1);
	}
}
int	init_philo(int ac, char **av)
{
	t_args *args;

	args = malloc(sizeof(t_args));
	args->philo_n = ft_atoi(av[1]);
	args->die_t = ft_atoi(av[2]);
	args->eat_t = ft_atoi(av[3]);
	args->sleep_t = ft_atoi(av[4]);
	args->times_eat = -1;
	if (args->philo_n < 1 || args->die_t < 0 || args->eat_t < 0
	|| args->sleep_t < 0 || args->philo_n > 250)
			return (0);
	if (ac == 6)
		args->times_eat = ft_atoi(av[5]);
	return(1);
}