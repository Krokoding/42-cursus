/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_func_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:02:10 by loris             #+#    #+#             */
/*   Updated: 2023/12/21 13:02:36 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	msg_exit(char *str)
{
	printf("%s\n", str);
	exit (0);
}

void	msem_manager(sem_t *sem, t_opcode opcode)
{
	if (opcode == LOCK)
	{
		if (sem_wait(sem))
			msg_exit("Semaphore error");
	}
	if (opcode == UNLOCK)
	{
		if (sem_post(sem))
			msg_exit("Semaphore error");
	}	
	if (opcode == DESTROY)
	{
		if (sem_destroy(sem))
			msg_exit("Semaphore error");
	}
}

/*
*	calculate remaining time and make small usleep instead of one big usleep
*	when the remaining time is less than 1000 usec, a busy while loop is used
*	to wait
*/
void	wait_func(long time_to_wait)
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
