/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:50:59 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/13 12:56:23 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_swaplst	**lst)
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

t_swaplst	*ft_pop(t_swaplst **a)
{
	t_swaplst	*top;

	if (a)
	{
		top = *a;
		*a = (*a)->next;
		top->next = NULL;
	}
	return (top);
}

t_swaplst	*ft_push(t_swaplst **a, t_swaplst **b)
{
	t_swaplst	*node;

	if (a && b)
	{
		node = ft_pop(a);
		if (node)
			ft_lstadd_f(b, node);
	}
	ft_putstr_fd("pb\n", 1);
	return (node);
}

void	ft_pushb(t_swaplst **a, t_swaplst **b)
{
	t_swaplst	*top;

	if (a && b)
	{
		top = ft_pop(a);
		if (top)
			ft_lstadd_f(b, top);
	}
	ft_putstr_fd("pa\n", 1);
}

void	ft_rotate(t_swaplst	**lst)
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
	ft_putstr_fd("ra\n", 1);
}
