/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:25:58 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 13:53:10 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strrchr(const char *string, int searchedChar)
{
	int	len;

	len = ft_strlen(string);
	while (len)
	{
		if (string[len] == searchedChar)
			return (string + len);
		len--;
	}
	return (0);
}
