/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:15:16 by loris             #+#    #+#             */
/*   Updated: 2023/10/19 17:09:32 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char					*dst;
	size_t					s_len;
	size_t					end;

	end = 0;
	s_len = ft_strlen(s);
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
