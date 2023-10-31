/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:45:39 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/30 19:28:25 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_lenx(unsigned int nb)
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
		ft_print_X(nb);
	if (i == 1)
		ft_print_x(nb);
	count += ptr_len(nb);
	return (count);
}
