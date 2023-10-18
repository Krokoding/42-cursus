/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:38:12 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 15:09:26 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memset(void *pointer, int value, size_t count)
{
	char	*ptr;
	int		i;
	
	i = count;
	ptr = pointer;
	while (count)
	{
		*ptr = value;
		ptr++;
		count--;
	}
	return (ptr - i);
}