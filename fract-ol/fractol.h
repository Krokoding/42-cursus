/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:54:37 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/22 18:44:09 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define GREEN 50
# define RED 40
# define BLUE 10

# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include "libft.h"
# include "math.h"
# include <stdlib.h>

typedef struct s_color
{
	unsigned int	red;
	unsigned int	blue;
	unsigned int	green;
}	t_color;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image_ptr;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	char	*addr;
	double	min_x;
	double	min_y;
	double	max_y;
	double	max_x;
	double	range_y;
	double	range_x;
	double	scale;
	double	start;
	int		selector;
	int		max_iter;
	double	diverge;
	int		width;
	int		height;
	double	t;
	double 	reel;
	double	image;
	t_color	color;
}	t_data;

int		color_set(int i, t_color *c, t_data *data);
int		key_press(int keysym, t_data *data);
int		color(int i);
int		movement(int keysym, t_data *data);
void	plot_line(t_data *data);
void	to_pixel(int x, int y, double echelle_x, t_data *data);
int		julia(double a, double b, t_data *data);
void	julia_change(int keysym, t_data *data);
int		mandelbrot(double a, double b, t_data *data);
int		colorchange(int keysim, t_color *color);
t_data	init(void);
void	welcome(void);
void	fractol_selector(int keysym, t_data *data);
int		fractol(double reel, double imaginaire, t_data *data);
void	reset_params(t_data *data);
int		mouse_centred_zoom(int keysim, int x, int y, t_data *data);
void	unzoom(t_data *data);
void	zoom(t_data *data, double ratio_pos_y, double ratio_pos_x);
int		close_windows(int keysym, t_data *data);
int 	argument_to_set(char *av, t_data *data);
void 	julia_s_set(char **av, t_data *data);

#endif