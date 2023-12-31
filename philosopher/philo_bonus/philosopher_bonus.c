/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:53:47 by loris             #+#    #+#             */
/*   Updated: 2023/12/22 15:38:07 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	main(int ac, char **av)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (0);
	if (ac == 5 || ac == 6)
	{
		if (!initialisation(ac, av, d))
			return (0);
		table(d);
		clean(d);
	}
	else
	{
		free(d);
		msg_exit("Please put 4 or 5 argument");
	}
}

int	clean(t_data *d)
{
	int i;
	int	status;

	i = -1;
	while (i < d->n_o_p)
	{
		wait(&status);
		if (status != 0)
		{
			break ;
		}
		i++;
	}
	kill_all(d);
	sem_close(d->data_lock);
	sem_close(d->msg_lock);
	sem_close(d->dead_lock);
	sem_close(d->no_eat_when_die);
	sem_close(d->fork_sem);
	free(d->philo);
	free(d->fork);
	free(d->id);
	free(d);
	return (1);
}

void	kill_all(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_o_p)
	{
		kill(data->id[i], SIGTERM);
	}
	exit (0);
}
