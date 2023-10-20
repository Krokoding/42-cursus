/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:33:34 by loris             #+#    #+#             */
/*   Updated: 2023/10/19 18:45:05 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set)
{
    int         start;
    int         end;

    end = ft_strlen(s1);
    start = 0;
    while (ft_strchr(set, s1[start]) != 0 && s1[start])
        start++;
    while (ft_strrchr(set, s1[end]) != 0)
        end--;
    return(ft_substr(s1, start, (end - start + 1)));
}