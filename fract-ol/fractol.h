/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkary-po <lkary-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:54:37 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/21 15:09:22 by lkary-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define GREEN 50
#define RED 40
#define BLUE 50

#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include "libft.h"
#include "math.h"

typedef struct s_color
{
	unsigned int	red;
	unsigned int	blue;
	unsigned int	green;
	
}   t_color;

typedef struct s_data
{
	void    *mlx_ptr;
	void    *win_ptr;
	void    *image_ptr;
	int     bit_per_pixel;
	int     size_line;
	int     endian;
	char    *addr;
	double	min_x;
	double	min_y;
	double	max_y;
	double	max_x;
	double	range_y;
	double	range_x;
	double	scale;
	double	start;
	t_color color;

}   t_data;


// typedef struct s_startval
// {
	
// }	t_startval;
int		color_set(int i, t_color *c);
int		key_press(int keysym, t_data *data);
int		color(int i);
int 	movement(int keysym, t_data *data);
void 	plot_line(t_data *data);
void	zoom(int key, t_data *data);
void 	to_pixel(int x, int y, double echelle, t_data *data);
int 	julia(double a, double b, t_data *data);
int		mandelbrot(double a, double b);
int		colorchange(int keysim, t_color *color);


#endif