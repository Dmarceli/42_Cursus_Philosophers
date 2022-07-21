#include "../incs/philo.h"

int main(int argc, char **argv)
{
	if(argparser(argc,argv))
		if(!init_philo(argc,argv))
			return (error_message());
	printf("All philo satisfied!\n");
	return (0);
}