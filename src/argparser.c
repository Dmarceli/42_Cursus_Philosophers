#include "../incs/philo.h"

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
		return(1);
	}
	else
		return(error_message());
}	