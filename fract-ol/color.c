/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:57 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/21 15:01:16 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_set(int i, t_color *c)
{
	unsigned int		red;
	unsigned int		green;
	unsigned int		blue;
	double	iternomalized;
	int		colori;

	
	if (i == 60)
		return (0x000000);
	iternomalized = (double)i / 100;
	red = (unsigned int)(255 * c->red  * iternomalized);
	blue = (unsigned int)(1 - (255 * c->blue * iternomalized));
	green = (unsigned int)(255 * c->green * iternomalized);
	colori = (red << 24) + (blue << 16) + (green << 8) + 255;
	return (colori);
}

int	colorchange(int keysim, t_color *color)
{
	if (keysim == XK_equal)
	{
		color->blue++;
		color->green++;
		color->red++;
	}
	if (keysim == XK_minus)
	{
		color->blue--;
		color->green--;
		color->red--;
	}
	return (0);
}