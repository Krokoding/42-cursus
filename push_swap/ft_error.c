/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:02:28 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/14 11:08:50 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_error(t_swaplst **pile_a)
{
	if (ft_check_double(pile_a))
	{
		ft_putstr_fd("Error", 1);
		ft_lstfree(pile_a);
		return (1);
	}
	return (0);
}

int	entrnt_checker(char **av, int end)
{
	int	i;
	int	j;

	i = 1;
	if (check_max_mintab(end, av) || check_max_minlst(av[1]))
	{
		ft_putstr_fd("Error", 1);
		return (1);
	}
	while (i < end)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] > '9' || av[i][j] < '0')
			&& av[i][j] != ' ' && av[i][j] != '-')
			{
				ft_putstr_fd("Error", 1);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_double(t_swaplst **pile_a)
{
	t_swaplst	*temp;
	t_swaplst	*iter;

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

int	check_max_mintab(int ac, char **av)
{
	int					i;
	long int			value;

	i = 1;
	while (i < ac)
	{
		value = ft_atoli(av[i]);
		if (value < -2147483648 || value > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	check_max_minlst(char *str)
{
	char				**list;
	long int			value;
	int					i;
	int					j;

	j = 0;
	i = 0;
	list = ft_split(str, ' ');
	while (list[i])
	{
		value = ft_atoli(list[i]);
		if (value < -2147483648 || value > 2147483647)
		{
			while (list[j])
				free(list[j++]);
			free(list);
			return (1);
		}
		i++;
	}
	j = 0;
	while (list[j])
		free(list[j++]);
	free(list);
	return (0);
}
