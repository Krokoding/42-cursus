/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:50:34 by loris             #+#    #+#             */
/*   Updated: 2023/12/11 13:52:27 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*diner_management(void *data)
{
	t_philos *philo;

	philo = (t_philos *)data;
	while (get_bool(philo->data->data_lock, philo->data->allthread_creat))
		;
	philo->data->start = time_getter();
	if (philo->n % 2 == 0)
		mutex_even_philo(philo);
	else
		mutex_odd_philo(philo);
	// eating
	eating(philo);
	// sleeping
	sleeping(philo);
	// thinking
	thinking(philo);
	return (data);
}
void	mutex_even_philo(t_philos	*philo)
{
	mmutex_manager(philo->next_fork.fork, LOCK);
	philo->next_fork.available = 0;
	mmutex_manager(philo->previous_fork.fork, LOCK);
	philo->previous_fork.available = 0;
}

void	mutex_odd_philo(t_philos *philo)
{
	mmutex_manager(philo->previous_fork.fork, LOCK);
	philo->previous_fork.available = 0;
	mmutex_manager(philo->next_fork.fork, LOCK);
	philo->next_fork.available = 0;
}