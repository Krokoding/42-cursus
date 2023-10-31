/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:51:54 by loris             #+#    #+#             */
/*   Updated: 2023/10/31 12:10:59 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		print_type_redirector(char c, va_list args);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_printf(const char *str_to_print, ...);
int		ptr_lenx(unsigned int nb);
void	ft_print_x(unsigned int nb);
void	ft_print_X(unsigned int nb);
int		ft_print_hex(unsigned int nb, int i);
int		ft_sizee(unsigned int nb);
char	*ft_uitoa(unsigned int n);
int		ft_print_uint(unsigned int n);
int		ptr_len(uintptr_t ull);
void	ft_pointer_hexa_printer(uintptr_t ull);
int		ft_print_pointer(unsigned long long ull);
int		ft_print_decimal(int nb);

#endif