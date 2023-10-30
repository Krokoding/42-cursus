/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:32:07 by loris             #+#    #+#             */
/*   Updated: 2023/10/30 14:41:29 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "../libft/libft.h"
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
		count += ft_print_pointer(va_arg(args, unsigned long long));
	else if (c == 'd')
		count += ft_print_decimal(va_arg(args, int));
	else if (c == 'i')
		count += ft_print_int(va_arg(args, int));
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
	
	va_start(args, str_to_print);
	while(str_to_print)
	{
		if (*str_to_print == '%')
			print_type_redirector(*(++str_to_print), args);
		else
			write(1, str_to_print, 1);
		str_to_print++;
	}
}

int main()
{
	int	i;

	i = 42;
	
	ft_printf("bonjour %p", i);
}
