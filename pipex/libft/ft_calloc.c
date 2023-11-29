/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:48:55 by loris             #+#    #+#             */
/*   Updated: 2023/10/23 09:18:48 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*t;

	if (elementSize == 0 || elementCount == 0)
		return (malloc(0));
	if ((SIZE_MAX / elementCount < elementSize)
		|| (SIZE_MAX / elementSize < elementCount))
		return (NULL);
	t = (void *)malloc(elementSize * elementCount);
	if (!t)
		return (NULL);
	ft_bzero(t, elementCount * elementSize);
	return (t);
}
/*
int main()
{
	char *t;
	int i = 0;
	
	t = calloc(10, 1);
	while (i < 10)
	{
		printf("%d", t[i]);
		i++;
	}
}
*/
