/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:00:08 by loris             #+#    #+#             */
/*   Updated: 2023/10/22 18:05:15 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list  *temp;

    temp = lst;
    if (!lst || !f)
        return ;
    while (temp)
    {
        (*f)(temp->content);
        temp = temp->next;
    }
}