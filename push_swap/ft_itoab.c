/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:43:15 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/07 14:22:35 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	char    *base;
    int     i;
    
	base = "01";
	size = ft_size_b(size);
	nbr_in_str = malloc((size + 1) * sizeof(char));
    if (nbr_in_str == 0)
		return (0);
    ft_bzero(nbr_in_str, size);

	nbr_in_str[1] = '\0';
	nbr_in_str[size] = '\0';
	while (--size > -1)
	{
		
		nbr_in_str[size] = (base[n % 2]);
		n = (n / 2);
	}
	return (nbr_in_str);
}
