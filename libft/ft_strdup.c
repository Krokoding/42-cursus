/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:31:52 by loris             #+#    #+#             */
/*   Updated: 2023/10/19 14:31:59 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *source)
{
	int		len;
	char	*t;
	int		i;

	i = 0;
	len = ft_strlen(source);
	t = malloc(sizeof(const char) * len + 1);
	if (t == NULL)
		return (0);
	while (i < len)
	{
		t[i] = source[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
