/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:39:31 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/13 13:03:42 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	verification_len_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\n' || base[i] == '\r'
			|| base[i] == '\f' || base[i] == '\v')
			return (0);
		i++;
		if (j < 2)
			return (0);
	}
	return (j);
}

int	nbr_in_base(char *str, char *base, int i)
{
	int	j;
	int	check;
	int	count;

	count = 0;
	check = 1;
	j = 0;
	while (check == 1 || str[i] == '\0')
	{
		check = 0;
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				check = 1;
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

int	pwr(int nbr_exposed, int exp)
{
	int	i;
	int	clone;

	clone = nbr_exposed;
	i = 0;
	if (exp == 0)
		return (1);
	while (i < exp - 1)
	{
		nbr_exposed *= clone;
		i++;
	}
	return (nbr_exposed);
}

int	to_dec(char *str, char *base, int len_base, int len_nbr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (len_nbr == 0)
	{
		while (str[j] != base[i])
			i++;
		return (i);
	}
	else
	{
		while (str[j] != base[i])
			i++;
	}
	return (to_dec(&str[j + 1], base,
			len_base, len_nbr - 1) + (i * pwr(len_base, len_nbr)));
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	j;
	int	signe;

	signe = 1;
	j = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	if ((verification_len_base(base) == 0 || nbr_in_base(str, base, i) == 0))
		return (0);
	j = nbr_in_base(str, base, i);
	return (to_dec(&str[i], base, verification_len_base(base), j - 1) * signe);
}
