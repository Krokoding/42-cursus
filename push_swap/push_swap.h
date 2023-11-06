/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:28:25 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/06 11:59:23 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct s_list
{
	void			*c;
	char			*bc;
	struct s_list	*next;
}				t_swaplst;

void	ft_pile_a_binary_normalizer(t_swaplst	*pile_a);