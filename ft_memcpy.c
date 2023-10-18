/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:38:54 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 16:17:53 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memcpy(void *destination, const void *source, size_t size)
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
	return (destination);	
}
/*
int main() {

	int array [] = {54,85,20,63,21};
	int *copy = NULL;
	int length = sizeof( int ) * 5;
	   

	copy = (int *) malloc( length );
	ft_memcpy( copy, array, length );
		

	for( length=0; length<5; length++ ) {
		printf( "%d ", copy[ length ] );
	}
	printf( "\n" );
		
	free( copy );
}
*/