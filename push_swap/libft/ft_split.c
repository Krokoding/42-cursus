/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:47:48 by loris             #+#    #+#             */
/*   Updated: 2023/11/08 17:00:58 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdlib.h>
#include <stdio.h>


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
size_t	ft_strlcpy(char *destination, const	char *source, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(source);
	i = 0;
	if (!destination || !source)
		return (0);
	if (size == 0)
		return (len);
	while (i < size -1 && source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (len);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char					*dst;
	size_t					s_len;
	size_t					end;

	end = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len > start)
		end = s_len - start;
	if (end > len)
		end = len;
	dst = malloc(end + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s[start], end + 1);
	return (dst);
}
*/
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
//#include <unistd.h>

int	ft_free(char **dst, int j)
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
			if (!dst[j] && ft_free(dst, j))
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
