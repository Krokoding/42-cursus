/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:31:52 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 12:47:33 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char * strdup( const char * source )
{
    int len;
    char *t;
    int i;
    
    i = 0;
    len = ft_strlen(source);
    t = malloc(sizeof(char) * len);
    while (i < len)
    {
        t[i] = source[i];
        i++;
    }
    return (t);
}