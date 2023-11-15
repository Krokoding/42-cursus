/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:43:15 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/06 09:49:43 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size_base(unsigned int nb)
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

char	*ft_itoa_base(unsigned int n, char *base)
{
	char			*nbr_in_str;
	int				size;

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

char	*ft_print_base(unsigned int nb)
{
	char	*str;

	str = ft_itoa_base(nb, "01");
	return (str);
}