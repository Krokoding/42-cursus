/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:42:22 by loris             #+#    #+#             */
/*   Updated: 2023/11/14 11:07:05 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_min(t_swaplst **pile_a)
{
	t_swaplst	*temp;
	int			pos;
	int			i;
	int			biggest_value;

	biggest_value = INT32_MAX;
	i = 0;
	pos = 0;
	temp = *pile_a;
	while (temp)
	{
		if (temp->c < biggest_value)
		{
			biggest_value = temp->c;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}

int	pos_max(t_swaplst **pile_a)
{
	t_swaplst	*temp;
	int			pos;
	int			i;
	int			biggest_value;

	biggest_value = INT32_MIN;
	i = 0;
	pos = 0;
	temp = *pile_a;
	while (temp)
	{
		if (temp->c > biggest_value)
		{
			biggest_value = temp->c;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}
