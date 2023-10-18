/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:48:10 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 12:08:18 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void * memchr( const void * memoryBlock, int searchedChar, size_t size )
{
    const char  *mblock;

    mblock = memoryBlock;
    while (size)
    {
        if (mblock == searchedChar)
            return (mblock);
        size--;
        mblock++;
    }
    return (0);
}