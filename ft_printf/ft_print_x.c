/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:45:39 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/30 14:42:46 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb / 16)
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
	if (nb > 16)
	{
		(ft_print_x(nb / 16));
		(ft_print_x(nb % 16));
	}
	else
		ft_putchar_fd(base[nb], 1);
}

void	ft_print_X(unsigned int nb)
{
	char							*base;

	base = "0123456789ABCDEF";
	if (nb > 16)
	{
		(ft_print_X(nb / 16));
		(ft_print_X(nb % 16));
	}
	else
		ft_putchar_fd(base[nb], 1);
}

int	ft_print_hex(unsigned int nb, int i)
{
	int	count;

	count = 0;
	if (i == 0)
		ft_print_x(nb);
	if (i == 1)
		ft_print_x(nb);
	count += ptr_len(nb);
	return (count);
}
