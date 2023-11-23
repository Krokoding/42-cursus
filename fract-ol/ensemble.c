/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:11 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/23 08:50:06 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double a, double b, t_data *data)
{
	int		i;
	double	result;
	double	temp;

	i = 0;
	while (i < data->max_iter && (fabs(a) + fabs(b)) < data->diverge)
	{
		temp = a * a - b * b + data->reel;
		b = 2 * a * b + data->image;
		a = temp;
		i++;
	}
	return (i);
}

int	mandelbrot(double b, double a, t_data *data)
{
	int		i;
	double	result;
	double	temp;
	double	r;
	double	im;

	r = 0;
	i = 0;
	i = 0;
	while (i < data->max_iter && (fabs(im) + fabs(r)) < data->diverge)
	{
		temp = r * r - im * im;
		im = 2 * r * im + a;
		r = temp + b;
		i++;
	}
	return (i);
}

void	julia_change(int keysym, t_data *data)
{
	if (keysym == XK_c)
		data->reel -= 0.01;
	if (keysym == XK_x)
		data->image -= 0.01;
	if (keysym == XK_l)
		data->t += 0.001;
}
