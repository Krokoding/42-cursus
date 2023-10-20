/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:48:55 by loris             #+#    #+#             */
/*   Updated: 2023/10/20 15:46:12 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_size(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = (n * -1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	char	*nbr_in_str;
	int		size;
	int		signe;
	long	n;
	
	n = nb;
	if (n < 0)
		signe = 1;
	size = (ft_size(n) + signe);
	nbr_in_str = malloc((long unsigned int)(size + 1));
	if (!nbr_in_str)
		return (0);
	if (signe == 1)
	{
		n = n * (-1);
		nbr_in_str[0] = '-';
	}
	nbr_in_str[size] = '\0';
	while (--size >= signe)
	{
		nbr_in_str[size] = (n % 10 + '0');
		n = (n / 10);
	}
	return (nbr_in_str);
}
/*
int main()
{
	int i;

	i = 0;
	char *c;
	c = ft_itoa(2147483647);
	while (c[i])
	{
		printf("%c", c[i]);
		i++;
	}
}
*/