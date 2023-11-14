/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:28:25 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/14 10:15:28 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_listb
{
	long int		c;
	char			*bc;
	struct s_listb	*next;
}				t_swaplst;

char		*find_next_top(t_swaplst **pile_a, int n);
char		*ft_itoa_b(int n, int size);

t_swaplst	*ft_lstn(int content);
t_swaplst	*ft_lstl(t_swaplst *lst);
t_swaplst	*find_smallest(t_swaplst *pile_a);
t_swaplst	*creat_pile_a(t_swaplst **pile_a, int ac, char **av);
t_swaplst	*ft_pop(t_swaplst **a);
t_swaplst	*ft_push(t_swaplst **a, t_swaplst **b);
t_swaplst	*push_to_b(t_swaplst **pile_a, t_swaplst **pile_b, int n);
t_swaplst	*creat_pile_avone(t_swaplst **pile_a, char *str);
t_swaplst	*ft_lstla(t_swaplst *lst);

int			ft_size_b(int nb);
int			main(int ac, char **av);
int			ft_lsts(t_swaplst *lst);
int			ft_pile_asize(t_swaplst **lst);
int			bin_check(char b);
int			lst_checker_binary(t_swaplst **pile, int n);
int			check_sort(t_swaplst **pile_a);
int			ft_check_double(t_swaplst **pile_a);
int			double_error(t_swaplst **pile_a);
int			entrnt_checker(char **av, int end);
int			check_max_minlst(char *str);
int			check_max_mintab(int ac, char **av);
int			pos_max(t_swaplst **pile_a);
int			pos_min(t_swaplst **pile_a);

void		ft_lstadd_f(t_swaplst **lst, t_swaplst *new);
void		ft_lstadd_ba(t_swaplst **lst, t_swaplst *new);
void		ft_rrotate(t_swaplst **lst);
void		ft_swap(t_swaplst	**lst);
void		ft_rotate(t_swaplst	**lst);
void		ft_pile_a_binary_normalizer(t_swaplst	**pile_a);
void		push_swap(t_swaplst **pile_a, t_swaplst	**pile_b);
void		push_to_a(t_swaplst **pile_a, t_swaplst **pile_b);
void		ft_print_each_list(t_swaplst **a);
void		ft_pushb(t_swaplst **a, t_swaplst **b);
void		ft_lstfree(t_swaplst **pile_a);
void   		four_sort(t_swaplst **pile_a, t_swaplst **pile_b);
void    	three_sort(t_swaplst **pile_a);
void    	chtoupsi_sort(t_swaplst **pile_a, t_swaplst **pile_b);

#endif