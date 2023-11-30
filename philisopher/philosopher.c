/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:53:47 by loris             #+#    #+#             */
/*   Updated: 2023/11/30 13:11:40 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int main()
{
	
}


int	table(int number_of_philosopher, )
{
	int	i;
	pthread_t	philosopher[number_of_philosopher];
	i = 0;
	
	while (i < number_of_philosopher)
	{
		pthread_create(&philosopher[i], NULL, philo_action, NULL);
	}
}

int	philo_action()
{
	
}

