/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:45:39 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/03 12:21:13 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			nb = nb / 16;
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
		nbr_in_str[size] = (base[n % 16]);
		n = (n / 16);
	}
	return (nbr_in_str);
}

int	ft_print_base(unsigned int nb, int base)
{
	char	*str;
	int		ret_valu;

	if (base == 1)
		str = ft_itoa_base(nb, "0123456789abcdef");
	if (base == 0)
		str = ft_itoa_base(nb, "0123456789ABCDEF");
	ret_valu = ft_print_str(str);
	free(str);
	return (ret_valu);
}
