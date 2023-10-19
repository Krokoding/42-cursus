/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:35:43 by loris             #+#    #+#             */
/*   Updated: 2023/10/19 11:50:59 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *first, const char *second, size_t length )
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (first[i] && second[i] && i < length)
	{
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	if (i == length)
		return (0);
	return (first[i] - second[i]);
}
