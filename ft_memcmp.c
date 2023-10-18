/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:55:42 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 13:44:25 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	const char	*ptr1;
	const char	*ptr2;

	ptr1 = pointer1;
	ptr2 = pointer2;
	while (size && *ptr1 && *ptr2)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}