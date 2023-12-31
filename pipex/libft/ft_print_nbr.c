/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:40:40 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/14 16:48:05 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_decimal(int nb)
{
	char	*num;
	int		i;

	num = ft_itoa(nb);
	i = ft_print_str(num);
	free(num);
	return (i);
}
