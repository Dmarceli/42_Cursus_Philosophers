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
	int					isdead;
	long				start_time;
	pthread_mutex_t		forks[999];
	t_philo 			*philo[999];


}		t_args;

typedef struct s_philo
{
	int		id;
	int		meals;
	double	last_meal;
	t_args	*args;

}				t_philo;

typedef struct s_all
{
	t_philo *philo[999];
}	t_all;

int main(int argc, char **argv);
int argparser(int ac, char **av);
int	isnum(char *str);
int	error_message(void);
int	init_philo(int ac, char **av);
void start_time(t_args *philo);
long current_time(t_args *philo);

#endif