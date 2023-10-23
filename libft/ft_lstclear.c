/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:09:37 by loris             #+#    #+#             */
/*   Updated: 2023/10/22 17:52:54 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *temp;
    
    if (!lst || !del)
        return ;
    while (*lst)
    {
        temp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = temp;
    }
}