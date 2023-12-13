/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:02:10 by loris             #+#    #+#             */
/*   Updated: 2023/12/12 16:33:47 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*mmalloc(size_t bytes)
{
	void *ret;

	ret = malloc(bytes);
	if (!ret)
		msg_exit("Malloc failed");
	return (ret);
}

void	msg_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void	mthread_manager(pthread_t *id, t_philos *philos, t_opcode opcode)
{

	if (opcode == CREATE)
		pthread_create(id, NULL, diner_management, philos);
	if (opcode == JOIN)
		pthread_join(*id, NULL);
}

void	mmutex_manager(pthread_mutex_t *mtx, t_opcode opcode)
{
	if (opcode == LOCK)
		pthread_mutex_lock(mtx);
	if (opcode == UNLOCK)
		pthread_mutex_unlock(mtx);
	if (opcode == INIT)
		pthread_mutex_init(mtx, NULL);
	if (opcode == DESTROY)
		pthread_mutex_destroy(mtx);
}

// write message
// time manager with calculation for the death
void	wait_func(long time_to_wait, t_philos *philo)
{
	long	start;
	long	elapsed;
	long	rem;

	start = time_getter();
	while (time_getter() - start < time_to_wait)
	{
		elapsed = time_getter() - start;
		rem = time_to_wait - elapsed;
		if (rem > 1000)
		{
			usleep(rem / 2);
			philo->time_left -= rem / 2;
			if (philo->time_left <= 0)
			{
				mmutex_manager(&philo->data->dead_lock, LOCK);
				if (!get_bool(philo->data->data_lock, philo->data->end))
				{
					msg_action(philo->n, time_getter() - philo->data->start, DIE);
					set_bool(philo->data->data_lock, true, &philo->data->end);
				}
				mmutex_manager(&philo->data->dead_lock, UNLOCK);
				exit(-1);
			}
		}
		else
			while (time_getter() - start < time_to_wait)
				;
	}
}



// time getter
long	time_getter()
{
	long time_in_ms;
	struct timeval	tv;
	
	if (-1 == gettimeofday(&tv, NULL))
		msg_exit("Gettimeofday error");
	time_in_ms = tv.tv_sec * 1000000;
	time_in_ms += tv.tv_usec;
	return (time_in_ms);
}