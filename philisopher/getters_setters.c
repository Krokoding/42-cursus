/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:09:40 by loris             #+#    #+#             */
/*   Updated: 2023/12/13 10:51:24 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	set_bool(pthread_mutex_t lock, bool value, bool *location)
{
	mmutex_manager(&lock, LOCK);
	*location = value;
	mmutex_manager(&lock, UNLOCK);
}

bool	get_bool(pthread_mutex_t lock, bool location)
{
	bool	ret;

	mmutex_manager(&lock, LOCK);
	ret = location;
	mmutex_manager(&lock, UNLOCK);
	return (ret);
}

void	set_long(pthread_mutex_t lock, long value, long *location)
{
	mmutex_manager(&lock, LOCK);
	*location = value;
	mmutex_manager(&lock, UNLOCK);
}

long	get_long(pthread_mutex_t lock, long location)
{
	long	ret;

	mmutex_manager(&lock, LOCK);
	ret = location;
	mmutex_manager(&lock, UNLOCK);
	return (ret);
}
