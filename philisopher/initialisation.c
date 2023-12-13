/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:50:20 by loris             #+#    #+#             */
/*   Updated: 2023/12/12 17:12:04 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void parsing(int ac, char **av, t_data *d)
{
	if (ac == 6)
		d->max_meal = ft_atoi(av[5]);
	else
		d->max_meal = 0;
	d->n_o_p = ft_atoi(av[1]);
	d->timer.d = ft_atoi(av[2]) * 1000;
	d->timer.e = ft_atoi(av[3]) * 1000;
	d->timer.s = ft_atoi(av[4]) * 1000;
}

//init table fork together and separate philos init
void	table_init(int ac, char **av, t_data *d)
{
	t_fork		*fork;
	int			i;

	parsing(ac, av, d);
	i = -1;
	d->fork = mmalloc(sizeof(t_fork) * d->n_o_p);
	d->end = false;
	set_bool(d->data_lock, false, &d->allthread_creat);
	set_bool(d->data_lock, false, &d->end);
	mmutex_manager(&d->data_lock, INIT);
	mmutex_manager(&d->dead_lock, INIT);
	while (++i < d->n_o_p)
	{
		mmutex_manager(&d->fork[i].fork, INIT);
		d->fork[i].fork_id = i;
	}
}

void	philo_init(int ac, char **av, t_data *d)
{
	t_philos	*philosopher;
	int			i;

	philosopher = malloc(sizeof(t_philos) * d->n_o_p);
	i = -1;
	while (++i < d->n_o_p)
	{	
		d->philo = philosopher;
		d->philo[i].data = d;
		d->philo[i].meal_count = 0;
		d->philo[i].n = i + 1;
		d->philo[i].time_left = d->timer.d;	
		d->philo[i].previous_fork = &d->fork[i];
		d->philo[i].next_fork = &d->fork[(i + 1) % d->n_o_p];
	}
}

void	initialisation(int ac, char **av, t_data *d)
{
	table_init(ac, av, d);
	philo_init(ac, av, d);
}

