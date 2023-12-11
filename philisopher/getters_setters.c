/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_setters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:09:40 by loris             #+#    #+#             */
/*   Updated: 2023/12/10 19:03:53 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool    set_bool(pthread_mutex_t lock, bool value, bool location)
{
	mmutex_manager(lock, LOCK);
	location = value;
	mmutex_manager(lock, UNLOCK);
}

bool    get_bool(pthread_mutex_t lock, bool location)
{
	bool    ret;
	
	mmutex_manager(lock, LOCK);
	ret = location;
	mmutex_manager(lock, UNLOCK);
	return (ret);
}

long    set_long(pthread_mutex_t lock, long value, long location)
{
	mmutex_manager(lock, LOCK);
	location = value;
	mmutex_manager(lock, UNLOCK);
}

long    get_long(pthread_mutex_t lock, long value, long location)
{
	bool    ret;
	
	mmutex_manager(lock, LOCK);
	ret = location;
	mmutex_manager(lock, UNLOCK);
	return (ret);
}
