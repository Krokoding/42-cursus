/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_management.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:59:42 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/07 19:26:26 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pile_a_binary_normalizer(t_swaplst	**pile_a)
{
	t_swaplst	*temp;
	int			size;
	int			i;
	
	i = 0;
	size = ft_pile_asize(pile_a);
	while (i < size)
	{
		temp = find_smallest(*pile_a);
		temp->bc = ft_itoa_b(i, size);
		i++;
	}
}

t_swaplst	*find_smallest(t_swaplst *pile_a)
{
	t_swaplst	*temp;
	int			value;
	t_swaplst	*ret_node;
	
	temp = pile_a;
	while (temp->bc)
		temp = temp->next;
	value = temp->c;
	while (temp)
	{
		if (temp->c <= value && !(temp->bc))
		{
			value = temp->c;
			ret_node = temp;
		}
		temp = temp->next;
	}
	return (ret_node);
}