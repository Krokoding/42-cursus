/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:32:07 by loris             #+#    #+#             */
/*   Updated: 2023/10/30 09:32:17 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

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


int    print_type_redirector(char c, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (c == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		count = ft_print_pointer(va_arg(args, unsigned long long));
	else if (c == 'd')
		count = ft_print_decimal(va_arg(args, int));
	else if (c == 'i')
		count = ft_print_int(va_arg(args, int));
	else if (c == 'u')
		count = ft_print_uint(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_print_x(va_arg(args, unsigned int));
	else if (c == 'X')
		count = ft_print_X(va_arg(args, unsigned int));
	else if (c == '%')
		count = write(1, "%", 1);
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
	int byte_number;

	byte_number = 0;
	while (*str)
	{
		byte_number = write(1, str, 1);
		str++;
	}
	return (byte_number);
}

int	ft_print_pointer(unsigned long long p)
{
	unsigned long long *ull;
	char	*base;
	
	base = "0123456789abcdef";
	ull = &p;
	if (p > 16)
		return (ft_print_pointer(p / 16));
}

int	len_hexadec(unsigned long long p)
{
	int	i;

	i = 0;
	while (p / 16)
	{
		p = p / 16;
		i++;
	}
	return (i);
}