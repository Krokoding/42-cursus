/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:32:58 by loris             #+#    #+#             */
/*   Updated: 2023/10/30 11:20:16 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int    print_type_redirector(char c, va_list args);
int	ft_print_char(char c);
int ft_printf(const char *str_to_print, ...);
int	ft_print_str(char *str);
int	ft_print_pointer(unsigned long long ull);
void	ft_print_pointertst(uintptr_t ull);



#endif