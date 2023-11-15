/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 08:40:27 by loris             #+#    #+#             */
/*   Updated: 2023/11/15 08:44:29 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
