/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:13:20 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/03 15:14:19 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size_base_p(uintptr_t nb)
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

char	*ft_itoa_base_p(uintptr_t n, char *base)
{
	char			*nbr_in_str;
	int				size;

	size = (ft_size_base_p(n));
	nbr_in_str = malloc((size + 1) * sizeof(char));
	if (nbr_in_str == 0)
		return (0);
	if (n != 0)
		nbr_in_str[1] = '\0';
	nbr_in_str[size] = '\0';
	while (--size > -1)
	{
		nbr_in_str[size] = (base[n % 16]);
		n = (n / 16);
	}
	return (nbr_in_str);
}

int	ft_print_base_p(unsigned long long nb)
{
	char	*str;
	int		ret_valu;

	if (nb == 0)
		ret_valu = write(1, "0x0", 3);
	else
	{
		ret_valu = write (1, "0x", 2);
		if (ret_valu < 0)
			return (-1);
		str = ft_itoa_base_p((uintptr_t)nb, "0123456789abcdef");
		ret_valu = ft_print_str(str);
		free(str);
		if (ret_valu < 0)
			return (-1);
		else
			ret_valu += 2;
	}
	return (ret_valu);
}
