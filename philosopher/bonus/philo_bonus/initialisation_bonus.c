/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:50:20 by loris             #+#    #+#             */
/*   Updated: 2023/12/16 15:41:16 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	parsing(int ac, char **av, t_data *d)
{
	if (ac == 6)
		d->max_meal = ft_atoi(av[5]);
	else
		d->max_meal = 0;
	d->n_o_p = ft_atoi(av[1]);
	d->timer.d = ft_atoi(av[2]) * 1000;
	d->timer.e = ft_atoi(av[3]) * 1000;
	d->timer.s = ft_atoi(av[4]) * 1000;
	if (d->n_o_p == 0 || d->timer.d == 0 || d->timer.e == 0 || d->timer.s == 0
		|| d->n_o_p >= 200)
		return (msg_exit("Error"));
	if (d->timer.d < 60000 || d->timer.e < 60000 || d->timer.s < 60000)
		return (msg_exit("Error"));
	return (1);
}

/*
*	Intialise all the value of the table that need to be initialized
*	Initialise the mutex
*	I first initialize the table and then the philosopher.
*	Table is in all philos and philo can be accessed in table
*	to manipulate this easier
*	Table is sent to the thread create
*/

int	table_init(int ac, char **av, t_data *d)
{
	int			i;

	if (!parsing(ac, av, d))
	{
		free(d);
		return (0);
	}
	i = -1;
	d->fork = malloc(sizeof(bool) * d->n_o_p);
	if (!d->fork)
		return (0);
	d->end = false;
	d->data_lock = sem_open("/data_lock_sem", O_CREAT, 0644, 1);
	d->dead_lock = sem_open("/dead_lock_sem", O_CREAT, 0644, 1);
	d->no_eat_when_die = sem_open("/no_eat_when_die_sem", O_CREAT, 0644, 1);
	d->no_eat_when_die = sem_open("/msg_lock_sem", O_CREAT, 0644, 1);
	d->fork_sem = sem_open("/fork_sem", O_CREAT, 0644, d->n_o_p);
	set_bool(&d->data_lock, false, &d->allthread_creat);
	set_bool(&d->data_lock, false, &d->end);
	d->first_iteration = 1;
	while (++i < d->n_o_p)
		d->fork[i] = false;
	return (1);
}

/*
*	initialize all philos and set them the adress of the next and
*	previous fork
*/

int	philo_init(int ac, char **av, t_data *d)
{
	t_philos	*philosopher;
	int			i;

	philosopher = malloc(sizeof(t_philos) * d->n_o_p);
	if (!philosopher)
	{
		free(d->fork);
		free(d);
		return (0);
	}
	i = -1;
	while (++i < d->n_o_p)
	{
		d->philo = philosopher;
		d->philo[i].data = d;
		d->philo[i].meal_count = 0;
		d->philo[i].n = i + 1;
		d->philo[i].time_left = d->timer.d;
		d->philo[i].previous_fork = &d->fork[i];
		d->philo[i].last_meal = time_getter();
		d->philo[i].next_fork = &d->fork[(i + 1) % d->n_o_p];
		d->philo[i].full = false;
	}
	return (1);
}

int	initialisation(int ac, char **av, t_data *d)
{
	if (!table_init(ac, av, d))
		return (0);
	if (!philo_init(ac, av, d))
		return (0);
	return (1);
}
