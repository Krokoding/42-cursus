/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:36:24 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/14 16:47:58 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (n != 0)
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
	int		i;

	str = ft_uitoa(n);
	i = ft_print_str(str);
	free(str);
	return (i);
}
