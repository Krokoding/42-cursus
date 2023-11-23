/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:39:19 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/23 08:41:26 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	plot_line(t_data *data)
{
	int		x;
	int		y;
	double	echelle_x;

	x = 0;
	echelle_x = data->range_x / data->width;
	while (x < data->width)
	{
		y = 0;
		while (y < data->height)
			to_pixel(x, y++, echelle_x, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->image_ptr, 0, 0);
}

void	to_pixel(int x, int y, double echelle_x, t_data *data)
{
	int		pixel;
	int		pos;
	double	r;
	double	i;
	double	echelle_y;

	echelle_y = data->range_y / data->height;
	r = (x * echelle_x) + data->min_x;
	i = (y * echelle_y) + data->min_y;
	pos = fractol(r, i, data);
	pixel = data->bit_per_pixel * x / 8 + data->size_line * y;
	*(int *)(data->addr + pixel) = color_set(pos, &data->color, data);
}

int	fractol(double r, double i, t_data *data)
{
	if (data->selector == 0)
		return (mandelbrot(r, i, data));
	if (data->selector == 1)
		return (julia(r, i, data));
	else
		return (0);
}

int	close_windows(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->image_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	ft_printf("Exit the programme.\n");
	exit(0);
	return (0);
}

int	movement(int keysym, t_data *data)
{
	data->range_x = (data->min_x - data->max_x) * -1;
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
