/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chtoupsi_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:11:27 by loris             #+#    #+#             */
/*   Updated: 2023/11/14 10:09:43 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_sort(t_swaplst **pile_a)
{
    int max;
    int min;

    max = pos_max(pile_a);
    min = pos_min(pile_a);
    if (pos_max == 0)
        ft_rotate(pile_a);
    if (pos_max == 1)
        ft_rrotate(pile_a);
    if (min != 0)
        ft_swap(pile_a);
}

void    four_sort(t_swaplst **pile_a, t_swaplst **pile_b)
{
    int min;
    int i;
    
    i = 0;
    min = pos_min;
    while (i < min)
        ft_rrotate(pile_a);
    ft_push(pile_a, pile_b);
    three_sort(pile_a);
    ft_push(pile_b, pile_a);
}



void    chtoupsi_sort(t_swaplst **pile_a, t_swaplst **pile_b)
{
    int size;

    if (check_sort(pile_a))
        return ;
    size = ft_pile_asize(pile_a);
    if (size == 2)
        ft_swap(pile_a);
    if (size == 3)
        three_sort(pile_a);
}