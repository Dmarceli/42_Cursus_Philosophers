#include "../incs/philo.h"

int	error_message(void)
{
	printf("\x1B[31mERROR!\n\x1B[0m");
	exit(0);
	return (0);
}
void	print_timestamp(t_args *args, int control, double time, int philo_id)
{
	if (args->isdead)
		return ;
	if (control == 0)
	{
		printf("%.f %d has taken a fork\n", time, philo_id);
		printf("%.f %d has taken a fork\n", time, philo_id);
	}
	else if (control == 1)
		printf("%.f %d is eating\n", time, philo_id);
	else if (control == 2)
		printf("%.f %d is sleeping\n", time, philo_id);
	else if (control == 3)
		printf("%.f %d is thinking\n", time, philo_id);
	else if (control == 4)
		printf("%.f %d died\n", time, philo_id);
}