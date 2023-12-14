/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:07:32 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/14 12:14:36 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

/*
*	Start all the thread and then set a bool value to synchronize they start
*	the !end_of_simulation loop is a infinite loop that check if nobody died
*	of if they are all full
*/

void	table(t_data *d)
{
	int			i;
	t_philos	*philosopher;

	philosopher = d->philo;
	i = -1;
	while (++i < d->n_o_p)
	{
		if (!mthread_manager(&philosopher[i].id, &philosopher[i], CREATE))
			return ;
	}
	set_bool(d->data_lock, true, &d->allthread_creat);
	if (!end_of_simulation(d))
		return ;
	i = -1;
	while (++i < d->n_o_p)
	{
		if (!mthread_manager(&philosopher[i].id, &philosopher[i], JOIN))
			return ;
	}
}
