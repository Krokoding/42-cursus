/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:07:32 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/20 14:58:38 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

/*
*	Start all the thread and then set a bool value to synchronize they start
*	the !end_of_simulation loop is a infinite loop that check if nobody died
*	of if they are all full
*/

void	table(t_data *d)
{
	int			i;

	i = -1;
	while (++i < d->n_o_p)
	{
		d->id[i] = pipe_creator(&d->philo[i]);
	}
	i = -1;
	while (++i < d->n_o_p)
		sem_post(d->start_all_together);
	set_long(d->data_lock, time_getter(), &d->start);
}

void	pipe_for_checking(t_data *d)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		end_of_simulation(d);
	}
}

int	pipe_creator(t_philos *philo)
{
	int	id;

	id = fork();
	if (id == -1)
		exit(0);
	if (!id)
	{
		diner_management(philo);
		exit(0);
	}
	return (id);
}
