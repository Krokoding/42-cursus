/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_entry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:05:34 by loris             #+#    #+#             */
/*   Updated: 2023/11/23 08:32:55 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int argument_to_set(char *av, t_data *data)
{
    if (ft_strncmp("M", av, 1) == 0)
    {
		data->selector = 0;
        return (2);
    }
	else if (ft_strncmp("J", av, 1) == 0)
    {
		data->selector = 1;
        return (1);
    }
    // else if (ft_strncmp("", av, 1) == 0)
    // {
	// 	data->selector = 2;
    //     return (1);
    // }
    return (0);
}

void julia_s_set(char **av, t_data *data)
{
    data->reel = ft_atof(av[2]);
    data->image = ft_atof(av[3]);
}