/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:55:42 by loris             #+#    #+#             */
/*   Updated: 2023/10/19 08:43:01 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)pointer1;
	ptr2 = (const unsigned char *)pointer2;
	while (size)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		size--;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	const char i[] = "qa";
	const char j[] = "qq";
	printf("%d\n", ft_memcmp(i, j, 2));
	printf("%d", memcmp(i, j, 2));	
}
*/