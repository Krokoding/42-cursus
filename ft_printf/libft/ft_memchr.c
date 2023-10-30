/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:48:10 by loris             #+#    #+#             */
/*   Updated: 2023/10/23 09:20:14 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned char	*mblock;

	mblock = (unsigned char *)memoryBlock;
	while (size--)
	{
		if (*mblock == ((unsigned char)searchedChar))
			return ((void *)mblock);
		mblock++;
	}
	return (0);
}
