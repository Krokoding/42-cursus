/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:36:24 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/31 14:12:11 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sizee(unsigned int nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	else
	{
		while (nb != 0)
		{
			nb = nb / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char			*nbr_in_str;
	int				size;

	size = (ft_sizee(n));
	nbr_in_str = malloc((size + 1) * sizeof(char));
	if (nbr_in_str == 0)
		return (0);
	nbr_in_str[1] = '\0';
	nbr_in_str[size] = '\0';
	while (--size > -1)
	{
		nbr_in_str[size] = (n % 10 + '0');
		n = (n / 10);
	}
	return (nbr_in_str);
}

int	ft_print_uint(unsigned int n)
{
	char	*str;

	str = ft_uitoa(n);
	ft_print_str(str);
	free(str);
	return (ft_sizee(n));
}
