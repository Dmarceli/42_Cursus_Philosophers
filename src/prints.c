#include "../incs/philo.h"

int	error_message(void)
{
	printf("\x1B[31mERROR!\n\x1B[0m");
	exit(0);
	return (0);
}
void	print_timestamp(int control, long time, int philo_id)
{
	if (control == 0)
	{
		printf("%ld %d has taken a fork\n", time, philo_id);
		printf("%ld %d has taken a fork\n", time, philo_id);
	}
	else if (control == 1)
		printf("%ld %d is eating\n", time, philo_id);
	else if (control == 2)
		printf("%ld %d is sleeping\n", time, philo_id);
	else if (control == 3)
		printf("%ld %d is thinking\n", time, philo_id);
	else if (control == 4)
		printf("%ld %d died\n", time, philo_id);
}