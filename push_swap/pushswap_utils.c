/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:15:23 by loris             #+#    #+#             */
/*   Updated: 2023/11/07 09:44:40 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bin_check(char *binary, int pos)
{
	if (binary[pos] == 1)
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

int	ft_pile_asize(t_swaplst *lst)
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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	nb;
	int	signe;

	signe = 1;
	nb = 0;
	i = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb = nb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nb * signe);
}