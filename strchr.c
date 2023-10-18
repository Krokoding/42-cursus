/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:50:25 by loris             #+#    #+#             */
/*   Updated: 2023/10/18 13:48:19 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strchr(const char *string, int searchedChar)
{
	while (*string)
	{
		if (*string == searchedChar)
			return (string);
		string++;
	}
	return (0);
}
