/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:07:32 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/13 10:44:41 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	table(t_data *d)
{
	int			i;
	t_philos	*philosopher;

	philosopher = d->philo;
	i = -1;
	while (++i < d->n_o_p)
		mthread_manager(&philosopher[i].id, &philosopher[i], CREATE);
	set_bool(d->data_lock, true, &d->allthread_creat);
	i = -1;
	while (++i < d->n_o_p)
		mthread_manager(&philosopher[i].id, &philosopher[i], JOIN);
}
