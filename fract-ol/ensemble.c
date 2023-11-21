/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ensemble.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:11 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/21 15:16:07 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia(double a, double b, t_data *data)
{
	int i;
	double result;
	double temp;

	i = 0;
	while (i < 60 && (fabs(a) + fabs(b)) < 3)
	{
		temp = a * a - b * b + data->start;
		b = 2 * a * b;
		a = temp;
		i++;
	}
	return (i);
}

int	mandelbrot(double a, double b)
{
	int i;
	double result;
	double temp;
	double	reel;
	double	imag;

	reel = 0;
	imag = 0;
	i = 0;
	while (i < 60 && (fabs(imag) + fabs(reel)) < 3)
	{
		temp = reel * reel - imag * imag;
		imag = 2 * reel * imag + a;
		reel = temp + b;
		i++;
	}
	return (i);
}