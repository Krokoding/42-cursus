/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:25:10 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/15 08:52:45 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_swaplst	*pile_a;
	t_swaplst	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	if (entrnt_checker(av, ac))
		return (1);
	if (ac == 2)
		pile_a = creat_pile_avone(&pile_a, av[1]);
	else if (ac > 2)
		pile_a = creat_pile_a(&pile_a, ac, av);
	if (double_error(&pile_a))
		return (1);
	if (checker(&pile_a, &pile_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");	
	ft_lstfree(&pile_a);
}

int	checker(t_swaplst **pile_a, t_swaplst **pile_b)
{
	char *line;

	line = get_next_line(0);
	ft_printf("oui");

	while (line)
	{
		line = get_next_line(0);
		operator_redirector(line, pile_a, pile_b);
		free(line);
	}
	if ((!(check_sort(pile_a))) || (pile_b))
		return (0);	
	else
		return (1);
}

void	operator_redirector(char *line, t_swaplst **pile_a, t_swaplst **pile_b)
{
	if (ft_strncmp(line, "sa", 2))
	{
		ch_swap(pile_a);
	}
	if (ft_strncmp(line, "sb", 2))
	{
		ch_swap(pile_b);
	}
	if (ft_strncmp(line, "ss", 2))
	{
		ch_swap(pile_a);
		ch_swap(pile_b);	
	}
	if (ft_strncmp(line, "pa", 2))
	{
		ch_push(pile_a, pile_b);
	}
	if (ft_strncmp(line, "pb", 2))
	{
		ch_pushb(pile_a, pile_b);
	}
	if (ft_strncmp(line, "ra", 2))
	{
		ch_rotate(pile_a);
	}
	if (ft_strncmp(line, "rb", 2))
	{
		ch_rotate(pile_b);
	}
	if (ft_strncmp(line, "rr", 2))
	{
		ch_rotate(pile_b);
		ch_rotate(pile_a);
	}
	if (ft_strncmp(line, "rra", 3))
	{
		ch_rrotate(pile_a);
	}
	if (ft_strncmp(line, "rrb", 3))
	{
		ch_rrotate(pile_b);
	}
	if (ft_strncmp(line, "rrr", 3))
	{
		ch_rrotate(pile_b);
		ch_rrotate(pile_a);
	}
}