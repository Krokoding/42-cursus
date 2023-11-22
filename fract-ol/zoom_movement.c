/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:15:13 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/22 08:42:49 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, t_data *data)
{
	data->range_x =  (data->min_x - data->max_x) * -1;
	data->range_y = (data->min_y - data->max_y) * -1;

	if (key == XK_1)
	{
		data->max_x = data->max_x - (data->range_x / 2) * data->scale;
		data->min_x = data->min_x + (data->range_x / 2) * data->scale;
		data->max_y = data->max_y - (data->range_y / 2) * data->scale;
		data->min_y = data->min_y + (data->range_y / 2) * data->scale;
	}
	if (key == XK_2)
	{
		data->max_x = data->max_x + (data->range_x / 2) * data->scale;
		data->min_x = data->min_x - (data->range_x / 2) * data->scale;
		data->max_y = data->max_y + (data->range_y / 2) * data->scale;
		data->min_y = data->min_y - (data->range_y / 2) * data->scale;
	}
}

int movement(int keysym, t_data *data)
{
	data->range_x =  (data->min_x - data->max_x) * -1;
	data->range_y = (data->min_y - data->max_y) * -1;
	if (keysym == XK_Up)
	{
		data->min_y -= data->range_y * data->scale;
		data->max_y -= data->range_y * data->scale;
	}
	if (keysym == XK_Down)
	{
		data->min_y += data->range_y / 2 * data->scale;
		data->max_y += data->range_y / 2 * data->scale;
	}
	if (keysym == XK_Left)
	{
		data->min_x -= data->range_x / 2 * data->scale;
		data->max_x -= data->range_x / 2 * data->scale;
	}
	if (keysym == XK_Right)
	{		
		data->min_x += data->range_x * data->scale;
		data->max_x += data->range_x * data->scale;
	}
	return (0);
}

int	mouse_centred_zoom(int keysim, t_data *data)
{
	
}

int	julia_change(int keysym, t_data *data)
{
	if (keysym == XK_c)
		data->start += 0.01;
	if (keysym == XK_x)
		data->start -= 0.01;
}

int	key_press(int keysym, t_data *data)
{
	julia_change(keysym, data);
	colorchange(keysym, &data->color);
	zoom(keysym, data);
	movement(keysym, data);
	plot_line(data);
	return(0);
}