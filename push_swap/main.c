/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:52:02 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/08 21:07:51 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_swaplst   *pile_a;
    t_swaplst   *pile_b;
    
    pile_a = NULL;
    pile_b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
    {
        ft_putstr_fd("Error\n", 1);
        return (1);
    }
    if (entrnt_checker(av[1], &pile_a))
        return (1);
    if (ac == 2)
        pile_a = creat_pile_avone(&pile_a, av[1]);
    else if (ac > 2)
        pile_a = creat_pile_a(&pile_a, ac, av);
    if (double_error(&pile_a))
        return (1);
    ft_pile_a_binary_normalizer(&pile_a);
    push_swap(&pile_a, &pile_b);
    ft_lstfree(&pile_a);
}
// things to to : check for entry no int, int_MIN int_MAX
int double_error(t_swaplst **pile_a)
{
    if (ft_check_double(pile_a))
    {
        ft_putstr_fd("Error", 1);
        ft_lstfree(pile_a);
        return (1);
    }
    return (0);
}
int entrnt_checker(char *str, t_swaplst **pile_a)
{
    
    if (ft_check_str_entry(str))
    {
        ft_putstr_fd("Error\n", 1);
        ft_lstfree(pile_a);
        return (1);
    }
    return (0);
}
int ft_check_str_entry(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (((str[i] > '9' || str[i] < '0') && str[i] != ' '))
            return (1);
        i++;
    }
    return (0);
}

int ft_check_double(t_swaplst **pile_a)
{
    t_swaplst   *temp;
    t_swaplst   *iter;

    temp = *pile_a;
    while (temp->next)
    {
        iter = temp->next;
        while (iter)
        {
            if (iter->c == temp->c)
                return (1);
            iter = iter->next;
        }
        temp = temp->next;
    }
    return (0);
}

t_swaplst    *creat_pile_a(t_swaplst **pile_a, int ac, char **av)
{
    int         i;
    int         value;
    t_swaplst   *node;
    
    i = 1;
    while (i < ac)
    {   
        value = ft_atoi(av[i]);
        node = ft_lstn(value);
        ft_lstadd_ba(pile_a, node);
        i++;
    }
    return (*pile_a);
}

t_swaplst   *creat_pile_avone(t_swaplst **pile_a, char *str)
{
    char        **list;
    int         value;
    t_swaplst   *node;
    int         i;

    i = 0;
    list = ft_split(str, ' ');
    while (list[i])
    {
        value = ft_atoi(list[i]);
        node = ft_lstn(value);
        ft_lstadd_ba(pile_a, node);
        i++;
    }
    i = 0;
    while (list[i])
    {
        free(list[i]);
        i++;
    }
    free(list);
    return (*pile_a);
}