/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:48:10 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 16:27:52 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	const char	*mblock;

	mblock = memoryBlock;
	while (size)
	{
		if (*mblock == searchedChar)
			return ((void *)mblock);
		size--;
		mblock++;
	}
	return (0);
}
