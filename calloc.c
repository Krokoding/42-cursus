/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:48:55 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 13:04:11 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

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
    if (t == NULL)
        return (0);
    bzero(t, elementCount * elementSize);
    return (t);
}

int main()
{
    char *t;
    int i = 0;
    
    t = calloc(10, 1);
    while (i < 10)
    {
        printf("%s", t[i]);
        i++;
    }
}