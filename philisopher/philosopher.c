/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:53:47 by loris             #+#    #+#             */
/*   Updated: 2023/12/14 12:34:28 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	main(int ac, char **av)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (ac == 5 || ac == 6)
	{
		if (!initialisation(ac, av, d))
		{
			free(d);
			return (0);
		}
		else
		{
			table(d);
			clean(d);
		}
	}
	else
	{
		free(d);
		msg_exit("Please put 4 or 5 argument");
	}
}

int	clean(t_data *d)
{
	free(d->philo);
	free(d->fork);
	free(d);
	return (1);
}