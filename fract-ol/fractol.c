#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include "libft.h"
#include "math.h"
#include "fractol.h"

int main(void)
{
	t_data data;

	data.color.red = RED;
	data.color.green = GREEN;
	data.color.blue = BLUE;
	data.start = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 900, "Fract'Ol");
	data.image_ptr =  mlx_new_image(data.mlx_ptr, 900, 900);
	data.addr = mlx_get_data_addr(data.image_ptr, &data.bit_per_pixel, &data.size_line, &data.endian);
	data.min_x = -2;
	data.max_x = 2;
	data.min_y = -2;
	data.max_y = 2;
	data.scale = 0.1;
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, key_press, &data);
	mlx_mouse_hook(data.win_ptr, mo)

	mlx_loop(data.mlx_ptr);
}

/*
	things to add : 
		- drag and drop with the mouse
		- mwhelleup/down mouse centered zoom
		- make the custommer choose when the progrqm start
		- implement some ensemble
*/