/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:11 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/22 15:15:21 by lkary-po         ###   ########.fr       */
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
		temp = a * a - b * b + data->start;
		b = 2 * a * b;
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
	double	reel;
	double	imag;

	reel = 0;
	imag = 0;
	i = 0;
	while (i < data->max_iter && (fabs(imag) + fabs(reel)) < data->diverge)
	{
		temp = reel * reel - imag * imag;
		imag = 2 * reel * imag + a;
		reel = temp + b;
		i++;
	}
	return (i);
}

void	julia_change(int keysym, t_data *data)
{
	if (keysym == XK_c)
		data->start += 0.01;
	if (keysym == XK_x)
		data->start -= 0.01;
	if (keysym == XK_l)
		data->t += 0.001;
}
