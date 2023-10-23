/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 10:47:00 by loris             #+#    #+#             */
/*   Updated: 2023/10/21 11:01:00 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list *temp;

    if (lst == NULL)
        return (0);
    temp = lst;
    while (temp->next != NULL)
        temp = temp->next;
    return (temp);
}