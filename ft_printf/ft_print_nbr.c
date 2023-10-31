/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:40:40 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/31 11:13:56 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(int nb)
{
	char	*num;
	int	i;
	
	num = ft_itoa(nb);
	i = ft_print_str(num);
	free(num);
	return (i);
}
