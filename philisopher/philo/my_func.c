/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:02:10 by loris             #+#    #+#             */
/*   Updated: 2023/12/14 12:26:50 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	msg_exit(char *str)
{
	printf("%s\n", str);
	return(0);
}

int	mthread_manager(pthread_t *id, t_philos *philos, t_opcode opcode)
{
	if (opcode == CREATE)
	{
		if (0 != pthread_create(id, NULL, diner_management, philos))
			return (0);
	}
	if (opcode == JOIN)
	{
		if (0 != pthread_join(*id, NULL))
			return (0);		
	}
	return (1);
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

/*
*	calculate remaining time and make small usleep instead of one big usleep
*	when the remaining time is less than 1000 usec, a busy while loop is used
*	to wait
*/

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
			usleep(rem / 2);
		else
		{
			while (time_getter() - start < time_to_wait)
				;
		}
	}
}
