/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:51:54 by loris             #+#    #+#             */
/*   Updated: 2023/11/03 15:11:49 by lkary-po         ###   ########.fr       */
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
char	*ft_uitoa(unsigned int n);
int		ft_print_uint(unsigned int n);
int		ft_print_base(unsigned int nb, int base);
char	*ft_itoa_base(unsigned int n, char *base);
int		ft_size_base(unsigned int nb);
int		ft_print_decimal(int nb);
int		ft_print_base_p(unsigned long long nb);
char	*ft_itoa_base_p(uintptr_t n, char *base);
int		ft_size_base_p(uintptr_t nb);
int		write_polemik(const char *str_to_print, va_list args, int i, int count);

#endif