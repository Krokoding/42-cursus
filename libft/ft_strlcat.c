/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:50:55 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/23 09:21:02 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;

	dest_size = ft_strlen(dst);
	i = 0;
	if (dest_size >= size)
		return (ft_strlen(src) + size);
	while (src[i] && (dest_size + i) < (size - 1))
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[i + dest_size] = '\0';
	return (dest_size + ft_strlen(src));
}
/*
int main()
{
	char	dst[] = "bon";
	char	src[] = "jour";
	
}
*/