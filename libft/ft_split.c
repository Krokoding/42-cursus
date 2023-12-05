/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:47:48 by loris             #+#    #+#             */
/*   Updated: 2023/11/24 15:56:26 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && ((!(s[i + 1])) || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

int	len_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

int	ft_libre(char **dst, int j)
{
	while (j >= 0)
	{
		free(dst[j]);
		j--;
	}
	free(dst);
	return (1);
}

char	**ft_spli(char const *s, char c, int i, int j)
{
	char	**dst;
	int		word;
	int		end;

	word = word_count(s, c);
	dst = malloc(sizeof(char *) * (word + 1));
	if (!dst)
		return (0);
	while (s[i])
	{
		end = 0;
		if (s[i] != c && ((i == 0) || (!(s[i - 1])) || s[i - 1] == c))
		{
			end = len_count(&s[i], c);
			dst[j] = ft_substr(s, i, end);
			if (!dst[j] && ft_libre(dst, j))
				return (0);
			j++;
		}
		i++;
	}
	dst[j] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	return (ft_spli(s, c, 0, 0));
}
