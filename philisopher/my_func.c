/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:02:10 by loris             #+#    #+#             */
/*   Updated: 2023/12/10 19:56:42 by loris            ###   ########.fr       */
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
	printf("%d\n", str);
	exit(1);
}

void	mthread_manager(pthread_t id, t_philos *philos, t_opcode opcode)
{
	if (opcode == CREATE)
		pthread_create(id, NULL, diner_management, philos);
	if (opcode == JOIN)
		pthread_join(id, NULL);
}

void	mmutex_manager(pthread_mutex_t mtx, t_opcode opcode)
{
	if (opcode == INIT)
		pthread_mutex_init(&mtx, NULL);
	if (opcode == DESTROY)
		pthread_mutex_destroy(&mtx);
}

// write message
// time manager with calculation for the death
void	timer(long	time_to_wait)
{
	long	start;
	long	timer;

	timer = 0;
	start = time_getter();
	while (timer < time_to_wait)
	{
		
	}
}


// time getter
long	time_getter()
{
	long time_in_ms;
	struct timeval	*tv;
	
	if (-1 == gettimeofday(tv, NULL))
		msg_exit("Gettimeofday error");
	time_in_ms = tv->tv_sec * 1000;
	time_in_ms += tv->tv_usec / 1000;
	return (time_in_ms);
}