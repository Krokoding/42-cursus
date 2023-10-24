/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:20:38 by loris             #+#    #+#             */
/*   Updated: 2023/10/24 14:40:05 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*node;
	node = malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (*lst == NULL)
		{
			*lst = new;
		}
		else
		{
			temp = ft_lstlast(*lst);
			temp->next = new;
		}
	}
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

int	ft_lst_check(t_list **lst)
{
	int		i;
	int		k;
	t_list	*temp;

	temp = *lst;
	k = 0;
	while (temp)
	{
		i = 0;
		while (temp->content[i])
		{
			if (temp->content[i] == '\n')
				return (0);
			k++;
			i++;
		}
		temp = temp->next;
	}
	return (0);
}