/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:09:40 by loris             #+#    #+#             */
/*   Updated: 2023/12/17 17:21:45 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	set_bool(sem_t *sem, bool value, bool *location)
{
	msem_manager(sem, LOCK);
	*location = value;
	msem_manager(sem, UNLOCK);
}

bool	get_bool(sem_t *sem, bool *location)
{
	bool	ret;

	msem_manager(sem, LOCK);
	ret = *location;
	msem_manager(sem, UNLOCK);
	return (ret);
}

void	set_long(sem_t *sem, long value, long *location)
{
	msem_manager(sem, LOCK);
	*location = value;
	msem_manager(sem, UNLOCK);
}

long	get_long(sem_t *sem, long *location)
{
	long	ret;

	msem_manager(sem, LOCK);
	ret = *location;
	msem_manager(sem, UNLOCK);
	return (ret);
}