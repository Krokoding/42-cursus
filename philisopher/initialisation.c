/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:50:20 by loris             #+#    #+#             */
/*   Updated: 2023/12/10 19:16:42 by loris            ###   ########.fr       */
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

	i = -1;
	philosopher = mmalloc(sizeof(t_philos) * d->n_o_p);
	fork = mmalloc(sizeof(t_fork) * d->n_o_p);
	parsing(ac, av, d);
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
		d->philo[i].next_fork = fork[(i + 1) % d->n_o_p].fork;
		d->philo[i].previous_fork = fork[i].fork;
		d->fork[i].fork_id = i;
		printf("%d\n", d->philo[i].data->n_o_p);
		mmutex_manager(d->fork[i].fork, INIT);
	}
}

