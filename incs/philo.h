#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "../libft/libft.h"

typedef struct t_arguments
{
	int					philo_n;
	int					die_t;
	int					eat_t;
	int					sleep_t;
	int					times_eat;
	pthread_mutex_t		forks[250];

}		t_args;

typedef struct t_philostates
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_rules		*args;
	pthread_t			thread_id;

}		t_philo;

int main(int argc, char **argv);
int argparser(int ac, char **av);
int	isnum(char *str);
int	error_message(void);
int	init_philo(int ac, char **av);

#endif