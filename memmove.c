/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:27:37 by loris             #+#    #+#             */
/*   Updated: 2023/10/17 14:05:10 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

void *ft_memmove(void *dest, const void *src, size_t count)
{
	char	*dst;
	const char	*s;

	dst = dest;
	s = src;
	while (count)
	{		
		printf("%c\n", *s);
		*dst = *s;
		dst++;
		s++;
		count--;
	}
}

#include <string.h>

int main ()
{
  char str[] = "memmove can be very useful......";
  ft_memmove (str+20,str+15,12);
  printf ("%s", str);
  return 0;
}