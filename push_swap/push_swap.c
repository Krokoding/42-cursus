#include "push_swap.h"

void	push_swap(t_swaplst **pile_a, t_swaplst	**pile_b)
{
	int	i;

	i = 0;
    while (!(check_sort(pile_a)))
    {
        push_to_b(pile_a, pile_b, i);
        push_to_a(pile_a, pile_b);
        i++;
    }
    
}

t_swaplst	*push_to_b(t_swaplst **pile_a, t_swaplst **pile_b, int n)
{
	t_swaplst	*node;
    char        *memo;

    memo = find_next_top(pile_a, n);
    while (lst_checker_binary(pile_a, n))
    {

        while ((*pile_a)->bc[n] != '1')
        {
              ft_rotate(pile_a);
        }
        node = ft_push(pile_a, pile_b);
    }
    while ((*pile_a)->bc != memo)
    {
        ft_rotate(pile_a);
    }


    return (node);
}

char    *find_next_top(t_swaplst **pile_a, int n)
{
    char *ret;
    t_swaplst   *temp;

    temp = *pile_a;
    while(temp)
    {
        if (temp->bc[n] == '0')
        {
            ret = temp->bc;
            return (ret);
        }
        temp = temp->next;

    }
    return (0);
}

void	push_to_a(t_swaplst **pile_a, t_swaplst **pile_b)
{
	while (*pile_b)
	{
		ft_pushb(pile_b, pile_a);
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

void    ft_print_each_list(t_swaplst **a)
{
    t_swaplst   *temp1 = *a;
    int i;

    i = 0;
    printf("\n\n~~ PILE A ~~\n\n");
    while (temp1 != NULL)
		{

			printf("pile a apres push[%d] = %d    //    ", i, temp1->c);
			printf("bc[%d] = %s     ||      \n", i, temp1->bc);
			temp1 = temp1->next;
			i++;
		}
}
