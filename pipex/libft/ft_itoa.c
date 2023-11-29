/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:48:55 by loris             #+#    #+#             */
/*   Updated: 2023/10/31 11:13:43 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_size(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = 1;
	nb++;
	if (n == 0)
		return (1);
	if (n < 0)
		nb = (n * -1);
	else
		nb = n;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*nbr_in_str;
	int				size;
	int				signe;
	unsigned int	nb;

	signe = 0;
	if (n < 0)
		signe = 1;
	size = (ft_size(n) + signe);
	nbr_in_str = malloc((size + 1) * sizeof(char));
	if (nbr_in_str == 0)
		return (0);
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	nbr_in_str[0] = '-';
	nbr_in_str[1] = '\0';
	nbr_in_str[size] = '\0';
	while (--size >= signe)
	{
		nbr_in_str[size] = (nb % 10 + '0');
		nb = (nb / 10);
	}
	return (nbr_in_str);
}
/*
int main()
{
	int i;

	i = 0;
	char	*c;
	c = ft_itoa(-9);
	printf("  %s\n", c);


}
*/