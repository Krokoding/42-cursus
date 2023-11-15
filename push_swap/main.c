/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:52:02 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/15 08:41:13 by loris            ###   ########.fr       */
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
	ft_pile_a_binary_normalizer(&pile_a);
	if (ft_pile_asize(&pile_a) < 6)
		chtoupsi_sort(&pile_a, &pile_b);
	else
		push_swap(&pile_a, &pile_b);
	ft_lstfree(&pile_a);
}
