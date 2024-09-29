#include "fractol.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

t_complex	calculate_z(int x, int y, t_fractal *fractal)
{
	t_map_range	new_range_x;
	t_map_range	old_range_x;
	t_map_range	new_range_y;
	t_map_range	old_range_y;
	t_complex	z;

	new_range_x.min = -2;
	new_range_x.max = 2;
	old_range_x.min = 0;
	old_range_x.max = WIDTH;
	new_range_y.min = 2;
	new_range_y.max = -2;
	old_range_y.min = 0;
	old_range_y.max = HEIGHT;
	z.x = (map(x, new_range_x, old_range_x) * fractal->zoom) + fractal->shift_x;
	z.y = (map(y, new_range_y, old_range_y) * fractal->zoom) + fractal->shift_y;
	return (z);
}
