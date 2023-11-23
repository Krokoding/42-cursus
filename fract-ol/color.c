/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:57 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/22 19:03:21 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_set(int i, t_color *c, t_data *data)
{
	unsigned int		red;
	unsigned int		green;
	unsigned int		blue;
	double				iternomalized;
	int					colori;

	if (i == data->max_iter)
		return (0x000000);
	iternomalized = (double)i / data->max_iter / data->t;
	red = (unsigned int)(c->red * iternomalized);
	blue = (unsigned int)(1 - (c->blue * iternomalized));
	green = (unsigned int)(c->green * iternomalized);
	colori = (red << 24) + (green << 16) + (blue << 8) + 255;
	return (colori);
}

int	colorchange(int keysim, t_color *color)
{
	if (keysim == XK_b)
		color->blue++;
	if (keysim == XK_g)
		color->green++;
	if (keysim == XK_r)
		color->red++;
	return (0);
}
