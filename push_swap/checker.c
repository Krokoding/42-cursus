/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:25:10 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/15 14:32:16 by lkary-po         ###   ########.fr       */
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
		return (1);
	if (entrnt_checker(av, ac))
		return (1);
	if (ac == 2)
		pile_a = creat_pile_avone(&pile_a, av[1]);
	else if (ac > 2)
		pile_a = creat_pile_a(&pile_a, ac, av);
	if (double_error(&pile_a))
		return (1);
	if (!checker(&pile_a, &pile_b))
		return (1);
	ft_lstfree(&pile_a);
	ft_lstfree(&pile_b);
}

int	checker(t_swaplst **pile_a, t_swaplst **pile_b)
{
	char	*line;

	while ((line))
	{
		line = get_next_line(0);
		if (line)
		{
			if (!((operator_redirector(line, pile_a, pile_b))
					|| normoperator_redirector(line, pile_a, pile_b)
					|| normoperator_redirector2(line, pile_a, pile_b)))
			{
				ft_printf("Error\n");
				return (0);
			}
			free(line);
		}
	}
	if (!(*pile_a) || (*pile_b) || (!(check_sort(pile_a))))
	{
		ft_printf("KO\n");
		return (0);
	}
	else
		ft_printf("OK\n");
	return (1);
}

int	operator_redirector(char *line, t_swaplst **pile_a, t_swaplst **pile_b)
{
	if (!ft_strncmp(line, "ss", 2))
	{
		ch_swap(pile_a);
		ch_swap(pile_b);
		return (1);
	}
	else if (!ft_strncmp(line, "pa", 2))
	{
		if (*pile_b)
			ch_push(pile_b, pile_a);
		return (1);
	}
	else if (!ft_strncmp(line, "pb", 2))
	{
		if (*pile_a)
			ch_push(pile_a, pile_b);
		return (1);
	}
	else
		return (0);
}

int	normoperator_redirector2(char *line, t_swaplst **pile_a, t_swaplst **pile_b)
{
	if (!ft_strncmp(line, "ra", 2))
	{
		ch_rotate(pile_a);
		return (1);
	}
	else if (!ft_strncmp(line, "rb", 2))
	{
		ch_rotate(pile_b);
		return (1);
	}
	if (!ft_strncmp(line, "sa", 2))
	{
		ch_swap(pile_a);
		return (1);
	}
	else if (!ft_strncmp(line, "sb", 2))
	{
		ch_swap(pile_b);
		return (1);
	}
	else
		return (0);
}

int	normoperator_redirector(char *line, t_swaplst **pile_a, t_swaplst **pile_b)
{
	if (!ft_strncmp(line, "rr", 2))
	{
		ch_rotate(pile_b);
		ch_rotate(pile_a);
		return (1);
	}
	else if (!ft_strncmp(line, "rra", 3))
	{
		ch_rrotate(pile_a);
		return (1);
	}
	else if (!ft_strncmp(line, "rrb", 3))
	{
		ch_rrotate(pile_b);
		return (1);
	}
	else if (!ft_strncmp(line, "rrr", 3))
	{
		ch_rrotate(pile_b);
		ch_rrotate(pile_a);
		return (1);
	}
	else
		return (0);
}
