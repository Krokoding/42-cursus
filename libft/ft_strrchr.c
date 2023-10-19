/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:25:58 by loris             #+#    #+#             */
/*   Updated: 2023/10/19 10:52:21 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	len;

	len = ft_strlen(string);
	while (len >= 0)
	{
		if (string[len] == searchedChar)
			return ((char *)string + len);
		len--;
	}
	if (searchedChar == '\0')
		return ((char *)string + len);
	return (0);
}
