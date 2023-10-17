/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:18:12 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/17 12:01:37 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	dest_len = ft_strlen(dst);
	i = dest_len;
	if (size <= i)
		return (size + (ft_strlen(src)));
	while (src[j])
	{
		if (j < size - dest_len - 1)
			dst[i++] = src[j];
		j++;
	}
	dst[i] = '\0';
	return (j + dest_len);
}
/*
int main()
{
	const char src[] = "bonjouri";
	char dst[7] = "plop";
	
	printf("strlcat = %zu", strlcat(dst, src, 4));
	printf("%s\n", dst);

	const char src1[] = "bonjouri";
	char dst1[7] = "plop";

	printf("ft_strlcat = %zu", ft_strlcat(dst1, src1, 4));
	printf("%s\n", dst1);
}
*/