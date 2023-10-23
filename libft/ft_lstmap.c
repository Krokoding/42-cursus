/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:05:37 by loris             #+#    #+#             */
/*   Updated: 2023/10/23 09:11:31 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_lst;
	
	while (lst)
	{
		temp = malloc(sizeof(t_list));
		if (!temp)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		temp->content = (*f)(lst->content);
		temp->next = NULL;
		ft_lstadd_back(&new_lst, temp);
		lst = lst->next;
	}
	return (new_lst);
}