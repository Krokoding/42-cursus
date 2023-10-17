/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:27:37 by loris             #+#    #+#             */
/*   Updated: 2023/10/17 16:20:46 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>


void *ft_memcpy(void *destination, const void *source, size_t size)
{
    unsigned char		*dest;
    const unsigned char	*src;

    src = source;
    dest = destination;
    while (size)
    {
        *dest = *src;
        dest++;
        src++;
        size--;
    }
}

int ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void *ft_memmove(void *dest, const void *src, size_t count)
{
	char		temp;
	const char	*s;
	char		*dst;
	size_t		i;

	i = count;
	dst = dest;
	s = src;
	if (ft_strlen(dst) < ft_strlen(s))
	{	
		while (i)
		{
			dst[i] = s[i];
			i--;
		}
	}
	if (ft_strlen(dst) > ft_strlen(s))
	{
		while (i < count)
		{
			dst[i] = s[i];
			i++;
		}
	}
}

#include <string.h>

int main ()
{
  char str[] = "memmove can be very useful......";
  memmove (str+20,str+15,11);
  puts (str);
  return 0;
}