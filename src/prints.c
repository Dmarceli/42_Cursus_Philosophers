#include "../incs/philo.h"

int	error_message(void)
{
	printf("\x1B[31mERROR!\n\x1B[0m");
	exit(0);
	return (0);
}
void	print_timestamp(int act, long time, int philo_id)
{
	if (act == 0)
	{
		printf("%ld philo %d has taken a fork\n", time, philo_id);
		printf("%ld philo %d has taken a fork\n", time, philo_id);
	}
	else if (act == 1)
		printf("%ld philo %d is eating\n", time, philo_id);
	else if (act == 2)
		printf("%ld philo %d is sleeping\n", time, philo_id);
	else if (act == 3)
		printf("%ld philo %d is thinking\n", time, philo_id);
	else if (act == 4)
		printf("%ld philo %d died\n", time, philo_id);
}