/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:13:20 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/30 11:39:47 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptr_len(uintptr_t ull)
{
	int	i;

	i = 0;
	while (ull / 16)
	{
		ull = ull / 16;
		i++;
	}
	return (i);
}

void	ft_pointer_hexa_printer(uintptr_t ull)
{
	char							*base;

	base = "0123456789abcdef";
	if (ull > 16)
	{
		(ft_print_pointer(ull / 16));
		(ft_print_pointer(ull % 16));
	}
	else
		ft_putchar_fd(base[ull], 1);
}

int	ft_print_pointer(unsigned long long ull)
{
	int	count;

	count = 0;
	count += write(1, "0x", 2);
	if (ull == 0)
		count += write(1, "0", 1);
	else
	{
		ft_pointer_hexa_printer((uintptr_t) &ull);
		count += ptr_len(ull);
	}

}