#include "../incs/philo.h"

long start_timer(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);
}

long current_time(t_args *data)
{
    long     timeMill;
    struct   timeval    ct;
    
    gettimeofday(&ct, NULL);
    timeMill = (ct.tv_sec * 1000 + ct.tv_usec / 1000) - data->start_time;
    return (1000 * timeMill);
}
