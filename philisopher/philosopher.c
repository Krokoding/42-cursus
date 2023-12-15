/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:53:47 by loris             #+#    #+#             */
/*   Updated: 2023/12/15 08:36:07 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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
	int	i;
	
	i = -1;
			write(1, "EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\n", 35);

	while (++i < d->n_o_p)
		mmutex_manager(&d->fork[i].fork, DESTROY);
	mmutex_manager(&d->data_lock, DESTROY);
	mmutex_manager(&d->dead_lock, DESTROY);
	free(d->philo);
	free(d->fork);
	free(d);
	return (1);
}