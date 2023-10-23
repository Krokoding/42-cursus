/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:02:00 by loris             #+#    #+#             */
/*   Updated: 2023/10/22 18:59:04 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;
    
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