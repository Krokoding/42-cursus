/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:43:15 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/14 15:20:40 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_b(int nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	else
	{
		while (nb)
		{
			nb = nb / 2;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa_b(int n, int size)
{
	char	*nbr_in_str;
	char	*base;
	int		i;

	base = "10";
	i = 0;
	size = ft_size_b(size);
	nbr_in_str = malloc((size + 1) * sizeof(char));
	if (nbr_in_str == 0)
		return (0);
	ft_bzero(nbr_in_str, size);
	nbr_in_str[1] = '\0';
	nbr_in_str[size] = '\0';
	while (i < size)
	{
		nbr_in_str[i] = (base[n % 2]);
		n = (n / 2);
		i++;
	}
	return (nbr_in_str);
}
