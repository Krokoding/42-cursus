/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:57:09 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/19 10:04:57 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *destination, const	char *source, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(source);
	i = 0;
	if (!destination || !source)
		return (0);
	if (size == 0)
		return (len);
	while (i < size -1 && source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (len);
}
