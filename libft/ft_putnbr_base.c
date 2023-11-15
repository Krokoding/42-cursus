/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:35:38 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/06 09:50:12 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	conv(unsigned int nbr, char *base, int len)
{
	if (nbr == 0)
		return ;
	conv(nbr / len, base, len);
	ft_putchar(base[nbr % len]);
}

int	len_base(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	error(char *base)
{
	int	i;
	int	j;
	int	len_b;

	i = 0;
	j = 0;
	len_b = len_base(base);
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = i;
		while (base[j] != '\0')
		{
			j++;
			if (base[i] == base[j])
				return (0);
		}
		if (len_b <= 1 || base[i] == 43 || base[i] == 45)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				len_b;
	int				error_check;
	unsigned int	nbr_abs;

	error_check = error(base);
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	if (error_check == 0)
		return ;
	len_b = 0;
	if (nbr < 0)
	{
		nbr_abs = -nbr;
		ft_putchar('-');
	}
	else
		nbr_abs = nbr;
	len_b = len_base(base);
	conv(nbr_abs, base, len_b);
}
