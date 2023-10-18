/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:32:58 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 16:51:53 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
	#include <stddef.h>
	#include <stdio.h>
	int	toupper(int c);
	int	toupper(int c);
	int	memcmp(const void *pointer1, const void *pointer2, size_t size);
	int	strncmp(const char *first, const char *second, size_t length );
	int	ft_strlen(char *str);
	int	ft_atoi(const char *nptr);
	int	ft_isprint(int c);
	int	ft_isdigit(char c);
	int	ft_isascii(int c);
	int	ft_isalpha(char *str);
	int	ft_isalnum(int c);
	size_t	strlcpy(char *destination, const	char *source, size_t size);
	size_t	ft_strlcat(char *dst, const char *src, size_t size);
	void	*ft_memset(void *pointer, int value, size_t count);
	void	*ft_memmove(void *dest, const void *src, size_t count);
	void	*ft_memcpy(void *destination, const void *source, size_t size);
	void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
	void	*calloc( size_t elementCount, size_t elementSize );
	void	ft_bzero(void *str, size_t n);
	char	*ft_strrchr(const char *string, int searchedChar);
	char	*ft_trnstr(const char *big, const char *little, size_t len);
	char	*ft_strdup(const char *source);
	char	*ft_strchr(const char *string, int searchedChar);
#endif