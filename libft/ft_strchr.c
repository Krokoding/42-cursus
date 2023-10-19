/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:25 by loris             #+#    #+#             */
/*   Updated: 2023/10/19 13:08:54 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *string, int searchedChar)
{
	unsigned char	*str;

	str = (unsigned char *)string;
	while (*str)
	{
		if (*str == (unsigned char)searchedChar)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)searchedChar == '\0')
		return ((char *)str);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	int	i;

	i = 'c';
	
	const char	c[] = "plopcplop";
	printf("%s\n", ft_strchr(c, i));
	printf("%s", strchr(c, i));
}
*/