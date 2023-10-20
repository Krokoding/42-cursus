/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:47:48 by loris             #+#    #+#             */
/*   Updated: 2023/10/20 08:42:46 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && i != 0 && s[i + 1] && s[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}
int len_count(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
char **ft_split(char const *s, char c)
{
	char	**dst;
	int		word;
	int		end;
	int		i;

	i = 0;
	word = word_count(s, c);
	dst = malloc(sizeof(char *) * word + 1);
	dst[0] = ft_substr(s, i, len_count(s, c));
	dst++;
	while (s[i])
	{
		end = 0;
		if (s[i] == c)
		{
			end = len_count(&s[i + 1], c);
			*dst = ft_substr(s, i, end);
			(*dst)++;
		}
		i++;
	}
	*dst = 0;
	return (dst);
}

int main()
{
	char const s[] = " split moi fdp ";
	char c = ' ';
	char **sp;
	
	sp = ft_split(s, c);
	while (**sp == 0)
	{
		printf("%s", *sp);
		(*sp)++;
	}
}