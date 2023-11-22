/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:15:13 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/22 15:15:28 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	unzoom(t_data *data)
{
	data->range_x = (data->min_x - data->max_x) * -1;
	data->range_y = (data->min_y - data->max_y) * -1;
	data->max_x = data->max_x + (data->range_x / 2) / (1 - data->scale) * 0.3;
	data->min_x = data->min_x - (data->range_x / 2) / (1 - data->scale) * 0.3;
	data->max_y = data->max_y + (data->range_y / 2) / (1 - data->scale) * 0.3;
	data->min_y = data->min_y - (data->range_y / 2) / (1 - data->scale) * 0.3;
	data->max_iter -= 1.5;
}

void	zoom(t_data *data, double ratio_pos_y, double ratio_pos_x)
{
	data->min_y += ratio_pos_y;
	data->max_y += ratio_pos_y;
	data->min_x += ratio_pos_x;
	data->max_x += ratio_pos_x;
	data->range_x = (data->min_x - data->max_x) * -1;
	data->range_y = (data->min_y - data->max_y) * -1;
	data->max_x = data->max_x - (data->range_x / 2) * data->scale;
	data->min_x = data->min_x + (data->range_x / 2) * data->scale;
	data->max_y = data->max_y - (data->range_y / 2) * data->scale;
	data->min_y = data->min_y + (data->range_y / 2) * data->scale;
	data->max_iter += 1.5;
}

int	mouse_centred_zoom(int keysim, int x, int y, t_data *data)
{
	int		pos_x;
	double	ratio_pos_x;
	int		pos_y;
	double	ratio_pos_y;

	data->range_x = (data->min_x - data->max_x) * -1;
	data->range_y = (data->min_y - data->max_y) * -1;
	pos_x = x - (data->width / 2);
	ratio_pos_x = (pos_x * data->range_x / data->width) * 0.3;
	pos_y = y - (data->height / 2);
	ratio_pos_y = (pos_y * data->range_y / data->height) * 0.3;
	if (keysim == 4)
	{
		zoom(data, ratio_pos_y, ratio_pos_y);
	}
	if (keysim == 5)
	{
		data->min_y += ratio_pos_y;
		data->max_y += ratio_pos_y;
		data->min_x += ratio_pos_x;
		data->max_x += ratio_pos_x;
		unzoom(data);
	}
	key_press(keysim, data);
	return (0);
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_windows(keysym, data);
	fractol_selector(keysym, data);
	julia_change(keysym, data);
	colorchange(keysym, &data->color);
	movement(keysym, data);
	plot_line(data);
	return (0);
}
