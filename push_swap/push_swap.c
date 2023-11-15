/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:56:58 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/15 10:34:14 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_swaplst **pile_a, t_swaplst	**pile_b)
{
	int	i;

	i = 0;
	while (!(check_sort(pile_a)))
	{
		push_to_b(pile_a, pile_b, i);
		push_to_a(pile_a, pile_b);
		i++;
	}
}

t_swaplst	*push_to_b(t_swaplst **pile_a, t_swaplst **pile_b, int n)
{
	t_swaplst	*node;
	char		*memo;

	memo = find_next_top(pile_a, n);
	while (lst_checker_binary(pile_a, n))
	{
		while ((*pile_a)->bc[n] != '1')
		{
			ft_rotate(pile_a);
		}
		node = ft_push(pile_a, pile_b);
	}
	while ((*pile_a)->bc != memo)
	{
		ft_rotate(pile_a);
	}
	return (node);
}

char	*find_next_top(t_swaplst **pile_a, int n)
{
	char		*ret;
	t_swaplst	*temp;

	temp = *pile_a;
	while (temp)
	{
		if (temp->bc[n] == '0')
		{
			ret = temp->bc;
			return (ret);
		}
		temp = temp->next;
	}
	return (0);
}

void	push_to_a(t_swaplst **pile_a, t_swaplst **pile_b)
{
	while (*pile_b)
	{
		ft_pushb(pile_b, pile_a);
	}
}

int	lst_checker_binary(t_swaplst **pile, int n)
{
	t_swaplst	*temp;

	temp = *pile;
	while (temp)
	{
		if (temp->bc[n] == '1')
		{
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
