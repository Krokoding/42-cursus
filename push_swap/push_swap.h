/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:28:25 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/07 14:39:53 by lkary-po         ###   ########.fr       */
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
	int				c;
	char			*bc;
	struct s_listb	*next;
}				t_swaplst;


char		*ft_itoa_b(int n, int size);

t_swaplst	*ft_lstn(int content);
t_swaplst	*ft_lstl(t_swaplst *lst);
t_swaplst	*find_smallest(t_swaplst *pile_a);

int			ft_size_b(int nb);
int			main(int ac, char **av);
int			ft_lsts(t_swaplst *lst);
int			ft_pile_asize(t_swaplst **lst);
int			bin_check(char b);

void		ft_lstadd_f(t_swaplst **lst, t_swaplst *new);
void		ft_rrotate(t_swaplst **lst);
void		ft_swap(t_swaplst	**lst);
void		ft_push(t_swaplst **from, t_swaplst **to);
void		ft_rotate(t_swaplst	**lst);
void		ft_pile_a_binary_normalizer(t_swaplst	**pile_a);
void   		creat_pile_a(t_swaplst **head, int ac, char **av);
void		push_swap(t_swaplst **pile_a, t_swaplst	**pile_b, int size);
void		push_to_b(t_swaplst **pile_a, t_swaplst **pile_b, int n);
void		push_to_a(t_swaplst **pile_a, t_swaplst **pile_b);

#endif