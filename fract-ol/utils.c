/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:39:19 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/21 19:09:46 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void plot_line(t_data *data)
{
	int x;
	int y;
	int pixel;
	int pos;
	int i;
	double  reel;
	double  imaginaire;
	double  echelle;

	i = 0;
	x = 0;
	echelle = data->range_x / 900;
	while (x < 900)
	{
		y = 0;
		while (y < 900)
			to_pixel(x, y++, echelle, data);
		x++;
	}     
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image_ptr, 0, 0);
}

void to_pixel(int x, int y, double echelle, t_data *data)
{
	int pixel;
	int pos;
	double  reel;
	double  imaginaire;
	
	reel = (x * echelle) + data->min_x;
	imaginaire =  (y * echelle) + data->min_y;
	pos = julia(reel, imaginaire, data);
	pixel = data->bit_per_pixel * x / 8 + data->size_line * y;

	*(int*)(data->addr + pixel) = color_set(pos, &data->color);
}