#include "../incs/philo.h"

long long	get_curr_time(void)
{
	struct timeval	time;
	long long	usec;
	long long	sec;
	long long	msec;

	gettimeofday(&time, NULL);
	usec = (time.tv_usec / 1000);
	sec = (time.tv_sec * 1000);
	msec = sec + usec;
	return (msec);
}
