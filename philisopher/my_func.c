/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:02:10 by loris             #+#    #+#             */
/*   Updated: 2023/12/13 12:01:40 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*mmalloc(size_t bytes)
{
	void	*ret;

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
	long	second_start;
	
	start = time_getter();
	while (time_getter() - start < time_to_wait)
	{
		elapsed = time_getter() - start;
		rem = time_to_wait - elapsed;
		if (rem > 1000)
		{
			usleep(rem / 50);
			philo->time_left -= rem / 50;
			if (philo->time_left <= 0)
				wait_func_bis(philo);
		}
		else
		{
			second_start = time_getter();
			while (time_getter() - start < time_to_wait)
			{
				if (philo->time_left <= 0)
					wait_func_bis(philo);
			}
				
			return;
		}
	}
}
