/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:45:39 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/03 09:30:07 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_lenx(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_print_x(unsigned int nb)
{
	char							*base;

	base = "0123456789abcdef";
	if (nb >= 16)
	{
		(ft_print_x(nb / 16));
		(ft_print_x(nb % 16));
	}
	else
		ft_putchar_fd(base[nb], 1);
}

void	ft_print_xupp(unsigned int nb)
{
	char							*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		(ft_print_xupp(nb / 16));
		(ft_print_xupp(nb % 16));
	}
	else
		ft_putchar_fd(base[nb], 1);
}

int	ft_print_hex(unsigned int nb, int i)
{
	int	count;

	count = 0;
	if (nb == 0)
	{
		count += write(1, "0", 1);
	}
	else if (i == 0)
		ft_print_xupp(nb);
	else if (i == 1)
		ft_print_x(nb);
	count += ptr_lenx(nb);
	return (count);
}
