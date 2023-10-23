/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:27:37 by loris             #+#    #+#             */
/*   Updated: 2023/10/23 09:20:27 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char		*s;
	char		*dst;
	size_t		i;

	i = 0;
	dst = (char *)dest;
	s = (char *)src;
	if (dst > s)
	{
		while (count-- > 0)
			dst[count] = s[count];
	}
	else if (dst < s)
	{
		while (i < count)
		{
			dst[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <string.h>
#include <stddef.h>
#include <stdio.h>

int main ()
{
  char str[] = "bojour ceci test";
  printf("%c\n", *(str+1));
  ft_memmove (str+5,str+1,7);
  puts (str);
  char str2[] = "bojour ceci test";
  memmove (str2+5,str2+1,7);
  puts (str2);
  return 0;
}
*/