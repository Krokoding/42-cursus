/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:18:47 by loris             #+#    #+#             */
/*   Updated: 2023/11/15 08:21:43 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ch_swap(t_swaplst	**lst)
{
	t_swaplst	*first;
	t_swaplst	*second;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst = second;
}

t_swaplst	*ch_push(t_swaplst **a, t_swaplst **b)
{
	t_swaplst	*node;

	if (a && b)
	{
		node = ft_pop(a);
		if (node)
			ft_lstadd_f(b, node);
	}
	return (node);
}

void	ch_pushb(t_swaplst **a, t_swaplst **b)
{
	t_swaplst	*top;

	if (a && b)
	{
		top = ft_pop(a);
		if (top)
			ft_lstadd_f(b, top);
	}
}

void	ch_rotate(t_swaplst	**lst)
{
	t_swaplst	*last;
	t_swaplst	*first;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	last = ft_lstl(*lst);
	first = *lst;
	last->next = first;
	*lst = first->next;
	first->next = NULL;
}
