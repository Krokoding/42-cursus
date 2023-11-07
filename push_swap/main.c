/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:52:02 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/07 09:42:55 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_swaplst   *head;
    creat_pile_a(&head, ac, av);
    ft_pile_a_binary_normalizer(head);
    t_swaplst   *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->c);
        printf("%s", temp->bc);

        temp = temp->next;
    }
}

void    creat_pile_a(t_swaplst **head, int ac, char **av)
{
    int         i;
    int         value;

    
    i = 1;
    while (i < ac)
    {   

        value = ft_atoi(av[i]);
        ft_lstadd_f(head, ft_lstn(value));
        i++;
    }
}