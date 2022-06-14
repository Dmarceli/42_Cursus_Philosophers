#include "../incs/philo.h"

void forkpicker(t_philo *p)
{
	p->fork = p->id;
	p->fork2 = (p->id + 1) % p->args->philo_n;
}