/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:15:23 by loris             #+#    #+#             */
/*   Updated: 2023/11/08 17:06:11 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bin_check(char b)
{
	if (b == '1')
		return (1);
	return (0);
}

t_swaplst	*ft_lstn(int content)
{
	t_swaplst	*node;

	node = malloc(sizeof(t_swaplst));
	if (!node)
		return (0);
	node->c = content;
	node->bc = NULL;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_f(t_swaplst **lst, t_swaplst *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lsts(t_swaplst *lst)
{
	int		i;
	t_swaplst	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	ft_pile_asize(t_swaplst **lst)
{
	int			i;
	t_swaplst	*temp;
	i = 0;

	temp = *lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}

	return (i);
}
int	check_sort(t_swaplst **pile_a)
{
	t_swaplst	*temp;
	
	temp = *pile_a;
	while(temp->next)
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