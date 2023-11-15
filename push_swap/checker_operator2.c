/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operator2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:22:11 by loris             #+#    #+#             */
/*   Updated: 2023/11/15 08:49:44 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ch_rrotate(t_swaplst **lst)
{
	t_swaplst	*last;
	t_swaplst	*second_last;

	if (lst == NULL || *lst == NULL || (*lst)->next == NULL)
		return ;
	second_last = NULL;
	last = *lst;
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
