/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:53:47 by loris             #+#    #+#             */
/*   Updated: 2023/12/05 13:15:38 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main(int ac, char **av)
{
	table(11, 2500000, 2000000, 1000000);
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
		data[i].start_time = time_management();
		data[i].time_left = time_to_die;
		data[i].timer.die = time_to_die;
		data[i].timer.eat = time_to_eat;
		data[i].timer.sleep = time_to_sleep;
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
	i = 0;
	while (i < number_of_philosopher)
	{
		pthread_mutex_destroy(&data[i].fork);
		i++;
	}
	free(data);
	free(philosopher);
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

// find a way to terminate all the threads when a condition is true
// manage the timing for the die message (timstamp)

void	*philo_action(void *data)
{
	double start;
	t_data *fata;
	double 	end;
	int		next_close_phil;

	fata = (t_data *)data;
	if (!even_odd_manager(fata))
		return (0);
}
int	even_odd_manager(t_data *data)
{
	if (data->philosophers_num % 2 == 0)
		return (even_philosopher(data));
	if (data->philosophers_num % 2 != 0)
		return (odd_philosopher(data));
}

int	odd_philosopher(t_data *data)
{
	double	time_think;
	while (1)
	{
		if (!slipi_time(data))
			return (0);
		time_think = time_to_think_calculator(data);
		if (!time_or_die(data, time_think))
			return (0);
		if (time_think)
			thinki_time(data, time_think);
		if (!eating_time(data))
		{
			return (0);
		}
	}
	return (1);
}

int	even_philosopher(t_data *data)
{
	double	time_think;
	int		i;

	i = 0;
	while (1)
	{
		if (i == 0 && data->philosophers_num == data->number_of_philosopher -1)
		{
			if (!slipi_time(data))
				return (0);
			time_think = time_to_think_calculator(data);
			if (!time_or_die(data, time_think))
				return (0);
			if (time_think)
				thinki_time(data, time_think);
		}
		i = 1;
		if (!eating_time(data))
		{
			return (0);
		}
		// printf("philo %d %f\n",data->philosophers_num, data->time_left);
		slipi_time(data);
		// printf("philo %d %f\n",data->philosophers_num, data->time_left);
		time_think = time_to_think_calculator(data);
		if (!time_or_die(data, time_think))
			return (0);
		if (time_think)
		{
			thinki_time(data, time_think);
			// printf("philo %d %f\n",data->philosophers_num, data->time_left);
		}
	}
	return (1);
}
int	time_or_die(t_data *data, double time)
{
	double time_before_message;

	time_before_message = data->time_left;
	data->time_left -= time;
	if (data->time_left <= 0)
	{
		printf("%d %d is sleeping\n", (int)(time_management() - data->start_time), data->philosophers_num);
		usleep(time_before_message);
		printf("%d %d died\n", (int)(time_management() - data->start_time), data->philosophers_num);
		return (0);
	}
	return (1);
}

int	eating_time(t_data *data)
{
	pthread_mutex_lock(&data->fork);
	printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	if (data->philosophers_num != ((data->number_of_philosopher - 1)))
	{
		pthread_mutex_lock(&data[1].fork);
		printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	}
	else
	{
		pthread_mutex_lock(&data[-(data->number_of_philosopher - 1)].fork);
		printf("%d %d has taken a fork\n", (int)(time_management() - data->start_time), data->philosophers_num);
	}
	printf("%d %d is eating\n", (int)(time_management() - data->start_time), data->philosophers_num);
	data->timer.start_eat = time_management() - data->start_time;
	data->time_left = data->timer.die;
	usleep(data->timer.eat);
	data->time_left -= data->timer.eat;
	if (data->philosophers_num != ((data->number_of_philosopher - 1)))
		pthread_mutex_unlock(&data[1].fork);
	else
		pthread_mutex_unlock(&data[-(data->number_of_philosopher - 1)].fork);
	pthread_mutex_unlock(&data->fork);
	printf("philo %d, finished eat\n", data->philosophers_num);
	return (1);
}

double	time_to_think_calculator(t_data *data)
{
	double	time_to_think;

	time_to_think = (data->timer.eat / 1000) - (data->timer.start_eat - (time_management() - data->start_time));
	return (time_to_think);
}