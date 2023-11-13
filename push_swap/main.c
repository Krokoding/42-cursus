/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:52:02 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/13 15:12:43 by lkary-po         ###   ########.fr       */
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
	push_swap(&pile_a, &pile_b);
	ft_lstfree(&pile_a);
}

t_swaplst	*creat_pile_a(t_swaplst **pile_a, int ac, char **av)
{
	int			i;
	int			value;
	t_swaplst	*node;

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

t_swaplst	*creat_pile_avone(t_swaplst **pile_a, char *str)
{
	char		**list;
	int			value;
	t_swaplst	*node;
	int			i;

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
