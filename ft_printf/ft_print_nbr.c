/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:40:40 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/30 14:28:35 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int nb)
{
	char	*num;
	int	i;

	num = ft_itoa(nb);
	i = ft_print_str(num);
	return (i);
}