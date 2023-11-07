/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:50:59 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/06 16:21:46 by loris            ###   ########.fr       */
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
void	ft_push(t_swaplst **from, t_swaplst **to)
{
	t_swaplst	*temp;
	
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}
void	ft_rotate(t_swaplst	**lst)
{
	t_swaplst	*last;
	t_swaplst	*first;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	last = ft_lstlast(*lst);
	first = *lst;
	last->next = first;
	*lst = first->next;
	first->next = NULL;
}

void	ft_rrotate(t_swaplst **lst)
{
	t_swaplst	*last;
	t_swaplst	*second_last;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last != NULL)
		second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}