/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:07:26 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 17:38:10 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(little[i]))
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (((j + i) < len) && (big[i + j] == little[j]) && (big[i + j]))
			{
				if (!(little[j + 1]))
				{
					return ((char *)(big + i));
					printf("yo\n");
				}
				j++;
			}
		}
		i++;
	}
	return (0);
}

/*
int main()
{
	const char big[] = "bonjour";
	const char little[] = "";
	char *result;

	result = strnstr(big, little, 4);
	printf("%s", result);

}
*/