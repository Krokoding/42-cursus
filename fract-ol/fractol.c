/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:19:54 by lkary-po          #+#    #+#             */
/*   Updated: 2023/11/23 08:49:01 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include "libft.h"
#include "math.h"
#include "fractol.h"

void	welcome(void)
{
	ft_printf("\n---------------------------------------------------------\n");
	ft_printf("*       'M' Key: Switch to the Mandelbrot Set.          *\n");
	ft_printf("*       'J' Key: Switch to the Julia Set.               *\n");
	ft_printf("* Mouse Wheel Up/Down: Zoom in and out of the fractal.  *\n");
	ft_printf("*  '+' and '-' Keys: Adjust the color of the fractal.   *\n");
	ft_printf("*       'C' and 'X' Keys: Adjust of the Julia.          *\n");
	ft_printf("---------------------------------------------------------\n\n");
	ft_printf(" Explore the depths of fractal with intuitive controls. \n");
	ft_printf("    Ready to dive into a world of endless patterns!     \n");
	ft_printf("\n********************************************************\n");
	ft_printf("*       1st param is for the set you want to see       *");
	ft_printf("\n*    2nd and 3rd param are the value for Julia set     *");
	ft_printf("\n********************************************************\n");

}

void	fractol_selector(int keysym, t_data *data)
{
	if (keysym == XK_m)
	{
		reset_params(data);
		data->selector = 0;
		ft_printf("Mandelbraut selected\n");
	}
	else if (keysym == XK_j)
	{
		reset_params(data);
		data->selector = 1;
		ft_printf("Julia selected\n");
	}
}

int	fractol_preselector(int ac, char **av, t_data *data)
{
	if (ac != 4)
	{
		welcome();
		return (0);
	}
	if (ft_strlen(av[1]) > 1)
		return (0);
	else
	{
		if (!argument_to_set(av[1], data))
			return (0);
		else if (argument_to_set(av[1], data) == 1)
			julia_s_set(av, data);
	}
	return (1);
}

void	reset_params(t_data *data)
{
	data->start = 0;
	data->min_x = -2;
	data->max_x = 2;
	data->min_y = -2;
	data->max_y = 2;
	data->scale = 0.1;
}

t_data	init(void)
{
	t_data	data;

	data.color.red = RED;
	data.color.green = GREEN;
	data.color.blue = BLUE;
	data.start = 0;
	data.min_x = -2;
	data.max_x = 2;
	data.min_y = -2;
	data.max_y = 2;
	data.scale = 0.1;
	data.max_iter = 60;
	data.diverge = 3;
	data.width = 900;
	data.height = 900;
	data.t = 0;
	return (data);
}

int	main(int ac, char *av[])
{
	welcome();
	t_data	data;
	
	data = init();
	
	if (!fractol_preselector(ac, av, &data))
		return (0);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.width, data.height, "");
	data.image_ptr = mlx_new_image(data.mlx_ptr, data.width, data.height);
	data.addr = mlx_get_data_addr(data.image_ptr, &data.bit_per_pixel,
			&data.size_line, &data.endian);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.win_ptr, 17, 0, close_windows, NULL);
	mlx_mouse_hook(data.win_ptr, mouse_centred_zoom, &data);
	mlx_loop(data.mlx_ptr);
}

/*
	things to add : 
		- drag and drop with the mouse
		- mwhelleup/down mouse centered zoom
		- make the custommer choose when the progrqm start
		- implement some ensemble
		- esc close
*/