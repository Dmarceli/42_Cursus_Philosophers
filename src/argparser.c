#include "../incs/philo.h"

int	error_message(void)
{
	printf("\x1B[31mERROR!\n\x1B[0m");
	exit(0);
	return (0);
}

int	isnum(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] > '9' || str[i] < '0')
			return (0);
	return (1);
}

int argparser(int ac, char **av)
{
	int i;
	i = 0;
	if (ac == 5 || ac == 6)
	{
		while (++i < ac)
			if (!av[i] || !isnum(av[i]))
				return(error_message());
		if(!init_philo(ac,av))
			return (error_message());
		return(1);
	}
	else
		return(error_message());
}	