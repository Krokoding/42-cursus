/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:50:55 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/18 13:51:28 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	dest_size;
	int	j;

	j = 0;
	dest_size = ft_strlen(dst);
	i = 0;
	while (i < size && dst[i])
		i++;
	if (i < size)
		return (ft_strlen(src) + i);
	while (src[j])
	{
		if (j < size - i - 1)
			dst[i++] = src[j];
		j++;
	}
	return (dest_size + j);
}
/*
int main()
{
	char	dst[] = "bon";
	char	src[] = "jour";
	
}
*/