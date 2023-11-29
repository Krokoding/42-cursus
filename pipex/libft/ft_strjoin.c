/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:51:07 by lkary-po          #+#    #+#             */
/*   Updated: 2023/10/23 09:20:59 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	size_t		len_tot;

	len_tot = (ft_strlen(s1) + ft_strlen(s2));
	s = malloc(len_tot + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, (ft_strlen(s1) + 1));
	ft_strlcat(s, s2, (len_tot + 1));
	return (s);
}
/*
int	main()
{
	int	i;
	char	*strs[4];
	char	*sep = " ";
	char	*tab;
	strs[0] = "hhh";
	strs[1] = "iii";
	strs[2] = "jjj";
	strs[3] = "kkk";
	tab = ft_strjoin(4, strs, sep);

	i = 0;	
	while (tab[i])
	{
		printf("%c", tab[i]);
		i++;
	}
}
*/
