/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:52:02 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/07 14:30:18 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int i;
    int size;

    i = 0;
    t_swaplst   *pile_a;
    t_swaplst   *pile_b;
    
    pile_a = NULL;
    pile_b = NULL;
    creat_pile_a(&pile_a, ac, av);
    size = ft_pile_asize(&pile_a);
    ft_pile_a_binary_normalizer(&pile_a);
    push_swap(&pile_a, &pile_b, size);
    t_swaplst   *temp;
    while (temp != NULL)
    {
        printf("c[%d] = %d    //    ", i, temp->c);
        printf("bc[%d] = %s     ||      \n", i, temp->bc);
        temp = temp->next;
        i++;
    }


}

void    creat_pile_a(t_swaplst **pile_a, int ac, char **av)
{
    int         i;
    int         value;

    
    i = 1;
    while (i < ac)
    {   

        value = ft_atoi(av[i]);
        ft_lstadd_f(pile_a, ft_lstn(value));
        i++;
    }
}