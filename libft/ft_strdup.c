/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:31:52 by loris             #+#    #+#             */
/*   Updated: 2023/10/19 11:31:10 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
