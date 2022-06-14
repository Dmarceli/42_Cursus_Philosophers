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
	double				start_time;
	pthread_t			philo[999];
	pthread_mutex_t		forks[999];
}		t_args;

typedef struct s_philo
{
	int		id;
	int		meals;
	double	last_meal;
	int		fork;
	int		fork2;
	
	t_args	*args;
}				t_philo;


typedef struct s_all
{
	t_philo *philo[999];
}	t_all;


int 	main(int argc, char **argv);
int 	argparser(int ac, char **av);
int		isnum(char *str);
int		error_message(void);
void	print_timestamp(int control, long time, int philo_id);
int		init_philo(int ac, char **av);
int		init_mutex(t_args *args);
void	 *philoact(void *data);
void 	start_time(t_philo *philo);
long	current_time(t_philo *philo);
void 	forkpicker(t_philo *p);


#endif