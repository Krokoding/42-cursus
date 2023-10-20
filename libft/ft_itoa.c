/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:48:55 by loris             #+#    #+#             */
/*   Updated: 2023/10/20 13:29:35 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	malloc_size(int n)
{
	int	i;

	i = 0;
	while ((n / 10) != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*nbr_in_str;
	int		size;
	int		signe;

	signe = 0;
	size = malloc_size(n);
	if (n < 0)
		signe = 1;
	nbr_in_str = malloc((long unsigned int)(malloc_size + 1 + signe));
	if (signe == 1)
	{
		n = n * (-1);
		nbr_in_str[0] = '-';
	}
	while (size >= signe)
	{
		nbr_in_str[size] = (n % 10);
		n = (n / 10);
		size--;
	}
	return (nbr_in_str);
}
