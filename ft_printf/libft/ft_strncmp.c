/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:35:43 by loris             #+#    #+#             */
/*   Updated: 2023/10/23 09:21:14 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *first, const char *second, size_t length )
{
	size_t				i;
	unsigned const char	*uc1;
	unsigned const char	*uc2;

	i = 0;
	uc1 = (unsigned const char *)first;
	uc2 = (unsigned const char *)second;
	if (length == 0)
		return (0);
	while (uc1[i] && uc2[i] && i < length)
	{
		if (uc1[i] != uc2[i])
			return (uc1[i] - uc2[i]);
		i++;
	}
	if (i == length)
		return (0);
	return (uc1[i] - uc2[i]);
}
