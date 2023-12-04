#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

struct data
{
    int number;
};

double	time_management(void)
{
	struct timeval tv;
	double	time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000;
	time_ms += tv.tv_usec / 1000;
	return (time_ms);
}
void    *routine(void *i)
{
    struct data *data;
    double  start_time;
    double  time;
    int j;


    data = (struct data *)i;
    j = (*data).number;
    if (j % 2 == 0)
    {
        printf("Test paire %d\n", (*data).number);
        start_time = time_management();
        usleep(3520000);
        time = time_management() - start_time;
        printf("slipi time paire =  %lf\n", time);
        printf("after sleep paire \n");
    }
    if (j % 2 != 2)
    {
        printf("Test ipaire %d\n", (*data).number);
        start_time = time_management();
        usleep(3520000);
        time = time_management() - start_time;
        printf("slipi time ipaire =  %lf\n", time);
        printf("after sleep ipaire \n");
    }
}




int main()
{
    pthread_t   *t;
    int lim, i;

    struct data *test;

    lim = 10;
    i = 0;
    test = malloc(sizeof(struct data) * lim);
    t = malloc(sizeof(pthread_t) * 10);
    while (i < lim)
    {
        test[i].number = i;
        pthread_create(&t[i], NULL, &routine, (void *)&test[i]);
        i++;
    }
    i = 0;
        while (i < lim)
    {
        pthread_join(t[i++], NULL);
    }
    return (0);
}