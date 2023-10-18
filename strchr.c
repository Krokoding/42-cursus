/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:25 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 16:21:26 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strchr(const char *string, int searchedChar)
{
	while (*string)
	{
		if (*string == searchedChar)
			return ((char *)string);
		string++;
	}
	return (0);
}
