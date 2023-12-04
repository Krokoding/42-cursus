/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:53:47 by loris             #+#    #+#             */
/*   Updated: 2023/12/04 10:18:37 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main(int ac, char **av)
{
	table(10, 5000000, 50000, 50000);
}


int	table(int number_of_philosopher, int time_to_die, int time_to_eat, int time_to_sleep)
{
	t_data		*data;
	pthread_t	*philosopher;
	int			i;

	data = malloc(sizeof(t_data) * number_of_philosopher);
	philosopher = malloc(sizeof(pthread_t) * number_of_philosopher);
	i = 0;
	while (i < number_of_philosopher)
	{
		data[i].philosophers_num = i;
		data[i].number_of_philosopher = number_of_philosopher;
		pthread_mutex_init(&data[i].fork, NULL);
		pthread_create(&philosopher[i], NULL, philo_action, &data[i]);
		i++;
	}
	i = 0;
	while (i < number_of_philosopher)
	{
		pthread_join(philosopher[i], NULL);
		i++;
	}
}

double	time_management(void)
{
	struct timeval tv;
	double	time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000;
	time_ms += tv.tv_usec / 1000;
	return (time_ms);
}

// make an even philo action function and an odd philo action function
// and call one or the other in the function that call them

void	*philo_action(void *data)
{
	double start;
	t_data *fata;
	double 	end;
	int		next_close_phil;

	
	fata = (t_data *)data;
	fata->start_time = time_management();

	if (fata->philosophers_num % 2 != 0)
	{
		eating_time(fata, fata->timer.eat);
	}
}

int	odd_philosopher()
{
	
}

int	eating_time(t_data *data, int time_eat)
{
	pthread_mutex_lock(&data->fork);
	printf("%lf ms, philosopher n %d take the fork n %d\n", (time_management() - data->start_time), data->philosophers_num, data->philosophers_num);
	if (data->philosophers_num != ((data->number_of_philosopher - 1)))
	{
		pthread_mutex_lock(&data[1].fork);
		printf("%lf ms, philosopher n %d take the fork n %d\n", (time_management() - data->start_time), data->philosophers_num, data[1].philosophers_num);
	}
	else
	{
		pthread_mutex_lock(&data[-(data->number_of_philosopher - 1)].fork);
		printf("%lf ms, philosopher n %d take the fork n %d\n", (time_management() - data->start_time), data->philosophers_num, data[-(data->number_of_philosopher - 1)].philosophers_num);		
	}
	data->timer.start_eat = time_management() - data->start_time;
	usleep(time_eat);
}

double	time_to_think_calculator(t_data *data)
{
	double	time_to_think;

	time_to_think = data->timer.eat - ((time_management() - data->start_time) - data->timer.start_eat);
}