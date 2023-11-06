/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:25:58 by loris             #+#    #+#             */
/*   Updated: 2023/10/23 09:21:19 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	len;

	len = ft_strlen(string);
	while (len >= 0)
	{
		if (string[len] == (char)searchedChar)
			return ((char *)(string + len));
		len--;
	}
	return (NULL);
}
// #include <stdio.h>

// int main()
// {
// 	const char s[] = "teste";
// 	printf("%s", ft_strrchr(s, 'x'));
// }