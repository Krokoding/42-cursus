/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:50:20 by loris             #+#    #+#             */
/*   Updated: 2023/12/11 13:54:31 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void parsing(int ac, char **av, t_data *d)
{

	d->n_o_p = ft_atoi(av[1]);
	d->timer.d = ft_atoi(av[2]);
	d->timer.e = ft_atoi(av[3]);
	d->timer.s = ft_atoi(av[4]);
}

void	initialisation(int ac, char **av, t_data *d)
{
	t_philos	*philosopher;
	t_fork		*fork;
	int			i;

	parsing(ac, av, d);
	i = -1;
	philosopher = malloc(sizeof(t_philos) * d->n_o_p);
	fork = mmalloc(sizeof(t_fork) * d->n_o_p);
	d->philo = philosopher;
	d->fork = fork;
	d->end = false;
	mmutex_manager(d->data_lock, INIT);
	while (++i < d->n_o_p)
	{
		d->philo[i].data = d;
		d->philo[i].meal_count = 0;
		d->philo[i].n = i + 1;
		d->philo[i].time_left = d->timer.d;
		d->philo[i].next_fork.fork = fork[(i + 1) % d->n_o_p].fork;
		d->philo[i].previous_fork.fork = fork[i].fork;
		d->fork[i].fork_id = i;
		mmutex_manager(d->fork[i].fork, INIT);
	}
}

