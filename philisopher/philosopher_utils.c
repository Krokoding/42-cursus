/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:08 by lkary-po          #+#    #+#             */
/*   Updated: 2023/12/12 14:46:35 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	signe;

	signe = 1;
	nb = 0;
	i = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * signe);
}

void	msg_action(int id, long timestamp, t_eatopcode opcode)
{
	if (opcode == EAT)
		printf("%ld %d is eating\n", timestamp / 1000, id);
	else if (opcode == DIE)
		printf("%ld %d died\n", timestamp / 1000, id);
	else if (opcode == SLEEP)
		printf("%ld %d is sleeping\n", timestamp / 1000, id);
	else if (opcode == FORK)
		printf("%ld %d has taken a fork\n", timestamp / 1000, id);
	else if (opcode == THINK)
		printf("%ld %d is thinking\n", timestamp / 1000, id);
	else
		msg_exit("Message wrong opcode");
}

void	end_simulation(t_philos *philo)
{
	if (get_bool(philo->data->data_lock, philo->data->end))
		exit(-1);
}