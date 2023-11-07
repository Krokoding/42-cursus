/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:43:15 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/07 09:59:23 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_baseb(int nb)
{
	int				i;

	i = 0;
	if (nb == 0)
		return (1);
	else
	{
		while (nb != 0)
		{
			nb = nb / 2;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa_binary(int n)
{
	char			*nbr_in_str;
	int				size;
	char			*base;

	base = "0, 1";
	size = (ft_size_base(n));
	nbr_in_str = malloc((size + 1) * sizeof(char));
	if (nbr_in_str == 0)
		return (0);
	nbr_in_str[1] = '\0';
	nbr_in_str[size] = '\0';
	while (--size > -1)
	{
		nbr_in_str[size] = (base[n % 2]);
		n = (n / 2);
	}
	return (nbr_in_str);
}