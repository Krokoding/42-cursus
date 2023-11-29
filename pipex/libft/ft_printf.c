/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:32:07 by loris             #+#    #+#             */
/*   Updated: 2023/11/14 16:43:58 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_type_redirector(char c, va_list args)
{
	int	count;

	if (c == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (c == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		count = ft_print_base_p(va_arg(args, unsigned long long));
	else if (c == 'd')
		count = ft_print_decimal(va_arg(args, int));
	else if (c == 'i')
		count = ft_print_decimal(va_arg(args, int));
	else if (c == 'u')
		count = ft_print_uint(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_print_base(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		count = ft_print_base(va_arg(args, unsigned int), 0);
	else if (c == '%')
		count = write(1, "%", 1);
	else
		return (0);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	byte_number;
	int	check;

	byte_number = 0;
	if (str == NULL)
	{
		byte_number = write(1, "(null)", 6);
		return (byte_number);
	}
	while (*str)
	{
		check = write(1, str, 1);
		if (check < 0)
			return (-1);
		else
			byte_number += check;
		str++;
	}
	return (byte_number);
}

int	ft_printf(const char *str_to_print, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (str_to_print == NULL)
		return (-1);
	va_start(args, str_to_print);
	count = write_polemik(str_to_print, args, 0, 0);
	return (count);
}

int	write_polemik(const char *str_to_print, va_list args, int i, int count)
{
	int	check_write;

	check_write = 0;
	while (str_to_print[i])
	{
		if (str_to_print[i] == '%')
		{
			check_write = print_type_redirector(str_to_print[++i], args);
			if (check_write < 0)
				return (-1);
			else
				count += check_write;
		}
		else
		{
			check_write = write(1, &str_to_print[i], 1);
			if (check_write < 0)
				return (-1);
			count += check_write;
		}
		i++;
	}
	return (count);
}
