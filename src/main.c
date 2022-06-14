#include "../incs/philo.h"

int main(int argc, char **argv)
{
	t_args philo;
	if(argparser(argc,argv))
		start_time(&philo);
	
	return (0);
}