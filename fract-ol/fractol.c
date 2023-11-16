#include <stdlib.h>
#include "mlx/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
}   t_data;

int handle_no_event(void *data)
{
    return (0);
}

int handle_input(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    return (0);
}

int main(void)
{
    t_data data;

    
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        return (0);
    data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 300, "pas mal les bzez");
    if (!data.win_ptr)
    {
        free(data.win_ptr);
        return (0);
    }

    mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
    mlx_key_hook(data.win_ptr, &handle_input, &data);

    mlx_loop(data.mlx_ptr);

    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}