#include "push_swap.h"

void	push_swap(t_swaplst **pile_a, t_swaplst	**pile_b, int size)
{
	int	i;

	i = 0;
    ft_print_each_list(pile_a, pile_b);
	push_to_b(pile_a, pile_b, i);
	push_to_a(pile_a, pile_b);
	push_to_b(pile_a, pile_b, i);
	push_to_a(pile_a, pile_b);
    ft_print_each_list(pile_a, pile_b);


}

void	push_to_b(t_swaplst **pile_a, t_swaplst **pile_b, int n)
{
	t_swaplst	*tem;

    while (lst_checker_binary(pile_a, n))
    {
        while ((*pile_a)->bc[n] != '1')
        {
              ft_rotate(pile_a);
        }
        ft_push(pile_a, pile_b);
    }
}

void	push_to_a(t_swaplst **pile_a, t_swaplst **pile_b)
{
	t_swaplst	*temp;

	temp = *pile_b;
	while (temp)
	{
        ft_putnbr_fd(temp->c, 1);
        ft_putstr_fd("\n", 1);
		ft_pushb(pile_b, pile_a);
		temp = temp->next;
	}
}

int lst_checker_binary(t_swaplst **pile, int n)
{
    t_swaplst   *temp;

    temp = *pile;
    while (temp)
    {
        if (temp->bc[n] == '1')
        {
            return (1);
        }
        temp = temp->next;
    }
    return (0);
}

void    ft_print_each_list(t_swaplst **a, t_swaplst **b)
{
    t_swaplst   *temp1 = *a;
    t_swaplst   *temp2 = *b;
    int i;
    int j;

    i = 0;
    j = 0;
    printf("\n\n~~ PILE A ~~\n\n");
    while (temp1 != NULL)
		{
			printf("pile a apres push[%d] = %d    //    ", i, temp1->c);
			printf("bc[%d] = %s     ||      \n", i, temp1->bc);
			temp1 = temp1->next;
			i++;
		}
    printf("\n\n~~ PILE B ~~\n\n");
    while (temp2 != NULL)
	{
		printf("pile b apres push[%d] = %d    //    ", j, temp2->c);
		printf("bc[%d] = %s     ||      \n", j, temp2->bc);
		temp2 = temp2->next;
		j++;
	}
}
