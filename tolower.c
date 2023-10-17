/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:29:12 by loris             #+#    #+#             */
/*   Updated: 2023/10/17 16:29:37 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int toupper(int c)
{
    if (c < 'Z' && c > 'A')
        c -= 32;
    return (c);
}
