/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:59:42 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/06 11:59:49 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pile_a_binary_normalizer(t_swaplst	*pile_a)
{
	t_swaplst	*temp;
	t_swaplst	*last_smaller;
	t_swaplst	*first;
	int			i;
	int			pile_a_size;
	int			value;
// Normalize (start with the smaller give him 0 in binary and so on)
	pile_a_size = ft_pile_asize(pile_a);
	i = 0;
	first = pile_a;
	temp = pile_a;
	last_smaller->c = pile_a->c;
	while (i < pile_a_size)
	{
		temp = first;
		while (temp)
		{
			while (temp->bc == NULL)
				temp = temp->next;
			value = temp->c;
			if (temp->c <= value)
			{
				value = temp->c;
				last_smaller = temp;
			}
		}
		temp = temp->next;
	}
	last_smaller->bc = ft_itoa_binary(i++);
}

