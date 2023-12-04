/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_and_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:44:13 by loris             #+#    #+#             */
/*   Updated: 2023/12/04 09:40:29 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int thinki_time(unsigned int time, double start, int philosopher_num)
{
	printf("%lf ms, philosopher n %d, is thinking\n", (time_management() - start), philosopher_num);
	usleep(time);
}

int slipi_time(unsigned int time, double start, int philosopher_num)
{
	printf("%lf ms, philosopher n %d is sleeping\n", (time_management() - start), philosopher_num);
	usleep(time);
}