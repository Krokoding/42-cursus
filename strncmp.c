/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:35:43 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 12:08:18 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int strncmp( const char * first, const char * second, size_t length )
{
    int i;

    i = 0;
    while (first[i] && second[i] && i < length)
    {
        if (first[i] != second[i])
            return (first[i] - second[i]);
        i++;
    }
    return (0);
}