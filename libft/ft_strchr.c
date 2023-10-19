/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:25 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 17:30:41 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *string, int searchedChar)
{
	while (*string)
	{
		if (*string == searchedChar)
			return ((char *)string);
		string++;
	}
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