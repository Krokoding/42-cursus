/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:32:37 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/20 18:43:01 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

int	except(int fd)
{
	ft_putchar('-', fd);
	ft_putchar('2', fd);
	return (147483648);
}

void	ft_putnbr_fd(int nb, int fd)
{
	int	neg;
	int	k;

	if (nb == 0)
		ft_putchar(0 + 48, fd);
	if (nb == -2147483648)
		nb = except(fd);
	if (nb < 0)
	{
		ft_putchar('-', fd);
		neg = nb * -1;
		ft_putnbr_fd(neg, fd);
	}
	if (nb <= 9 && nb > 0)
		ft_putchar(nb + 48, fd);
	if (nb >= 10)
	{
		k = nb;
		nb = nb / 10;
		ft_putnbr_fd(nb, fd);
		ft_putchar(k % 10 + 48, fd);
	}
}
