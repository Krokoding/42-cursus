/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:28:25 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/07 09:45:26 by loris            ###   ########.fr       */
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

int			bin_check(char *binary, int pos);
int			ft_size_b(int nb);
int			main(int ac, char **av);
int			ft_lsts(t_swaplst *lst);
int			ft_pile_asize(t_swaplst *lst)

void		ft_lstadd_f(t_swaplst **lst, t_swaplst *new);
void		ft_rrotate(t_swaplst **lst);
void		ft_swap(t_swaplst	**lst);
void		ft_push(t_swaplst **from, t_swaplst **to);
void		ft_rotate(t_swaplst	**lst);
void		ft_pile_a_binary_normalizer(t_swaplst	*pile_a);
void   		 creat_pile_a(t_swaplst **head, int ac, char **av);

#endif