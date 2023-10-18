/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:38:12 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 13:47:26 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memset(void *pointer, int value, size_t count)
{
	char	*ptr;

	ptr = pointer;
	while (count)
	{
		*ptr = value;
		ptr++;
		count--;
	}
}
