#include "fractol.h"

static void	assign_color(int x, int y, t_fractal *fractal, int i)
{
	int			color;

	color = map(i, (t_map_range){BLACK, WHITE}, (t_map_range){0,
			fractal->iterations_definition});
	my_pixel_put(x, y, &fractal->img, color);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z = calculate_z(x, y, fractal);
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			assign_color(x, y, fractal, i);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
