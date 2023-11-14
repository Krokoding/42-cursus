/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:59:53 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/14 10:23:48 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swaplst	*ft_lstla(t_swaplst *lst)
{
	t_swaplst	*temp;

	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ft_lstfree(t_swaplst **pile_a)
{
	t_swaplst	*temp;

	temp = *pile_a;
	while (*pile_a)
	{
		temp = (*pile_a)->next;
		free((*pile_a)->bc);
		free(*pile_a);
		(*pile_a) = temp;
	}
}

int	check_sort(t_swaplst **pile_a)
{
	t_swaplst	*temp;

	temp = *pile_a;
	while (temp->next)
	{
		if (temp->c > (temp->next)->c)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_lstadd_ba(t_swaplst **lst, t_swaplst *new)
{
	t_swaplst	*temp;

	if (lst && new)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			temp = ft_lstla(*lst);
			temp->next = new;
		}
	}
}
