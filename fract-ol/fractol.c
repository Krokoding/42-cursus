#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <unistd.h>
#include "libft.h"
#include "math.h"


typedef struct
{
	long int reel;
	long int imag;
}   complex;

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

}   t_data;



int multiply_two_complex(double a, double b)
{
	int i;
	double result;
	double temp;

	i = 0;
	while (i < 60)
	{
		if (b + a > 3)
			return (1);
		temp = a * a - b * b - 1.11111;
		b = 2 * a * b;
		a = temp;
		i++;
	}
	return (0);
}

void plot_line(t_data *data)
{
	// complex pos;
	int x;
	int y;
	int iter;
	int sum_complex;
	int pixel;
	int pos;
	int i;
	double  reel;
	double  imaginaire;
	double  echelle_x;
	double  echelle_y;

	i = 0;
	x = 0;
	echelle_x = data->range_x / 900;
	echelle_y = data->range_y / 900;
	while (x < 900)
	{
		y = 0;
		while (y < 900)
		{
			reel = (x * echelle_x) - data->min_x;
			imaginaire =  (y * echelle_y) - data->min_y;
			pos = multiply_two_complex(reel, imaginaire);
			if (pos < 0)
				pos *= -1;
			if (pos == 1)
			{
				pixel = data->bit_per_pixel * x / 8 + data->size_line * y;
				*(int*)(data->addr + pixel) = 0x985f53;
				i++;
			}
			else
			{
				pixel = data->bit_per_pixel * x / 8 + data->size_line * y;
				*(int*)(data->addr + pixel) = 0x000000;
				i++;
			}
			y++;
		}
		x++;
	}     
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image_ptr, 0, 0);
}

int	zoom(int key, t_data *data)
{
	data->range_x =  (data->min_x - data->max_x) * -1;
	data->range_y = (data->min_y - data->max_y) * -1;

	if (key == XK_1)
	{
		ft_printf("42\n");

		data->max_x = data->max_x - (data->range_x / 2) * data->scale;
		data->min_x = data->min_x + (data->range_x / 2) * data->scale;

		data->max_y = data->max_y - (data->range_y / 2) * data->scale;
		data->min_y = data->min_y + (data->range_y / 2) * data->scale;
		plot_line(data);
	}
	if (key == XK_2)
	{
		data->max_x = data->max_x + (data->range_x / 2) * data->scale;
		data->min_x = data->min_x - (data->range_x / 2) * data->scale;

		data->max_y = data->max_y + (data->range_y / 2) * data->scale;
		data->min_y = data->min_y - (data->range_y / 2) * data->scale;
		plot_line(data);
	}
}

int handle_input(int keysym, t_data *data)
{

	data->range_x =  (data->min_x - data->max_x) * -1;
	data->range_y = (data->min_y - data->max_y) * -1;

	zoom(keysym, data);
	if (keysym == XK_Up)
	{
		data->min_y += data->range_y * data->scale;
		data->max_y += data->range_y * data->scale;
		ft_printf("%d\n", keysym);
	}
	if (keysym == XK_Down)
	{
		data->min_y -= data->range_y * data->scale;
		data->max_y -= data->range_y * data->scale;
		ft_printf("%d\n", keysym);
	}
	if (keysym == XK_Left)
	{
		data->min_x += data->range_x * data->scale;
		data->max_x += data->range_x * data->scale;
		ft_printf("%d\n", keysym);
	}
	if (keysym == XK_Right)
	{		
		data->min_x -= data->range_x * data->scale;
		data->max_x -= data->range_x * data->scale;
		ft_printf("%d\n", keysym);
	}
	plot_line(data);
	data->scale *= data->scale;
	return (0);
}

int main(void)
{
	t_data data;

	
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 900, 900, "pas mal les bzez");
	data.image_ptr =  mlx_new_image(data.mlx_ptr, 900, 900);
	data.addr = mlx_get_data_addr(data.image_ptr, &data.bit_per_pixel, &data.size_line, &data.endian);

	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, handle_input, &data);
	data.min_x = -2;
	data.max_x = 2;
	data.min_y = -2;
	data.max_y =-2;
	data.scale = 0.1;

	mlx_loop(data.mlx_ptr);
}
