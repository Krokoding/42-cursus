/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:03:09 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/13 13:03:14 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_swaplst	*ft_lstl(t_swaplst *lst)
{
	t_swaplst	*temp;

	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
