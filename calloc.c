/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:48:55 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 12:56:11 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    bzero(void *str, size_t n)
{
    char    *c;

    c = str;

    while (n)
    {
        *c = 0;
        n--;
        c++;
    }
}

void * calloc( size_t elementCount, size_t elementSize )
{
    char    *t;
    
    t = malloc(sizeof(char) * (elementSize * elementCount));
    bzero(t, elementCount * elementSize);
    return (t);
}