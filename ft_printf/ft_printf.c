/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:32:07 by loris             #+#    #+#             */
/*   Updated: 2023/10/31 09:19:50 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int    print_type_redirector(char c, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (c == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		count += ft_print_pointer(va_arg(args, int));
	else if (c == 'd')
		count += ft_print_decimal(va_arg(args, int));
	else if (c == 'i')
		count += ft_print_decimal(va_arg(args, int));
	else if (c == 'u')
		count += ft_print_uint(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_print_hex(va_arg(args, unsigned int), 1);
	else if (c == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (c == '%')
		count += write(1, "%", 1);
	else
		return (0);
	return (count);
}

int	ft_print_char(char c)
{
   return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	byte_number;

	byte_number = 0;
	while (*str)
	{
		byte_number = write(1, str, 1);
		str++;
	}
	return (byte_number);
}

int ft_printf(const char *str_to_print, ...)
{
	va_list args;
	int count;
	int	i;
	
	i = 0;
	count = 0;
	va_start(args, str_to_print);
	while(str_to_print[i])
	{
		if (str_to_print[i] == '%')
		{
			i++;
			count += print_type_redirector(str_to_print[i], args);
		}
		else
			count += write(1, &str_to_print[i], 1);
		i++;
	}
	return (count);
}
