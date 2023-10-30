/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:38:12 by loris             #+#    #+#             */
/*   Updated: 2023/10/23 09:20:32 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *pointer, int value, size_t count)
{
	char	*ptr;
	int		i;

	i = count;
	ptr = pointer;
	while (count)
	{
		*ptr = value;
		ptr++;
		count--;
	}
	return (ptr - i);
}
