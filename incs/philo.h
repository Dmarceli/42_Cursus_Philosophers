/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarceli <dmarceli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:25 by dmarceli          #+#    #+#             */
/*   Updated: 2022/08/30 16:49:01 by dmarceli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define USED 1
# define FREE 0

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct t_arguments
{
	int					philo_n;
	int					die_t;
	int					eat_t;
	int					sleep_t;
	int					times_eat;
	int					isdead;
	pthread_mutex_t		isdead_mutex;
	pthread_mutex_t		last_meal_mutex;
	long long			start_time;
	pthread_mutex_t		*print;
	pthread_t			philo[999];
	pthread_t			check_death;
	pthread_mutex_t		forks[999];

}		t_args;

typedef struct s_philo
{
	int		id;
	int		meals;
	long	last_meal;
	long	last_sleep;
	int		fork;
	int		fork2;
	t_args	*args;
}				t_philo;

typedef struct s_all
{
	t_philo	*philo[999];
}	t_all;

int				main(int argc, char **argv);
int				ft_atoi(const char *str);
int				argparser(int ac, char **av);
int				isnum(char *str);
int				error_message(void);
void			print_states(int control, long time, t_philo *philo);
int				init_philo(int ac, char **av);
int				init_mutex(t_args *args);
pthread_mutex_t	*init_print_mutex(void);
void			*philoact(void *data);
void			forkpicker(t_philo *p);
void			pickup_fork(t_philo *philo);
void			eat(t_philo *philo);
void			philo_sleep(t_philo *p);
long long		get_curr_time(void);
int				isanyonedead(t_philo *philo);
void			*deathchecker(void *data);
void			destroy_mutex(t_philo *philo);

#endif