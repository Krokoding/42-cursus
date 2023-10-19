/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:57:09 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/18 17:38:48 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

size_t	ft_strlcpy(char *destination, const	char *source, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && source[i])
	{
		destination[i] = source[i];
		i++;
	}
	i = 0;
	while (*source)
	{
		source++;
		i++;
	}
	return (i);
}
