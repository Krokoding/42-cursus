/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:07:32 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/12 12:44:20 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	table(t_data *d)
{
	int	i;
	t_philos *philosopher;
	
	philosopher = d->philo;
	i = -1;
	// start all thread
	while (++i < d->n_o_p)
	{
		mthread_manager(&philosopher[i].id, &philosopher[i], CREATE);
	}
	// wait all thread
	set_bool(d->data_lock, true, &d->allthread_creat);
	// check if death
	// while (!get_bool(d->data_lock, d->end) && get_bool(d->data_lock,))
	// check if full
	// join
	i = -1;
	while (++i < d->n_o_p)
	{
		mthread_manager(&philosopher[i].id, &philosopher[i], JOIN);
	}
}
