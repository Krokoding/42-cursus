#include "push_swap.h"

void	push_swap(t_swaplst **pile_a, t_swaplst	**pile_b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{

		push_to_b(pile_a, pile_b, i);
		ft_putstr_fd("\n\n", 1);
		push_to_a(pile_a, pile_b);
		i++;
	}
}

void	push_to_b(t_swaplst **pile_a, t_swaplst **pile_b, int n)
{
	t_swaplst	*tem;
	tem = *pile_a;
	while (tem)
	{
		if (tem->bc[n] == '1')
		{
			ft_push(pile_a, pile_b);
		}
		tem = tem->next;
	}
}

void	push_to_a(t_swaplst **pile_a, t_swaplst **pile_b)
{
	t_swaplst	*temp;

	temp = *pile_b;
	while (temp)
	{
		write(1, "d", 1);
		ft_push(pile_b, pile_a);
		write(1, "u", 1);
		temp = temp->next;
	}
}