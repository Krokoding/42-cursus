/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:26:59 by loris             #+#    #+#             */
/*   Updated: 2023/10/17 12:34:44 by loris            ###   ########.fr       */
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