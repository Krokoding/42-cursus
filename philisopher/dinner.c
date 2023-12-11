/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:34 by loris             #+#    #+#             */
/*   Updated: 2023/12/10 19:36:49 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void    diner_management(t_philos *philo)
{
	while (get_bool(philo->data->data_lock, philo->data->allthread_creat))
		;
	if (philo->n % 2 == 0)
		mutex_even_philo(philo);
	else
		mutex_odd_philo(philo);
	// eating
	// sleeping
	// thinking
}
void	mutex_even_philo(t_philos	*philo)
{
	mmutex_manager(philo->next_fork, LOCK);
	mmutex_manager(philo->previous_fork, LOCK);	
}

void	mutex_odd_philo(t_philos *philo)
{
	mmutex_manager(philo->previous_fork, LOCK);
	mmutex_manager(philo->next_fork, LOCK);
}