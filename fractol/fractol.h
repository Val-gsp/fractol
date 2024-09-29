#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Error"

# define WIDTH   800
# define HEIGHT  800

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF

# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractal;

typedef struct s_map_range
{
	double	min;
	double	max;
}	t_map_range;

int				ft_strncmp(char *s1, char *s2, int n);
void			putstr_fd(char *s, int fd);
void			fractal_init(t_fractal *fractal);
void			fractal_render(t_fractal *fractal);
t_complex		square_complex(t_complex z);
void			my_pixel_put(int x, int y, t_img *img, int color);
void			mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
t_complex		calculate_z(int x, int y, t_fractal *fractal);
double			map(double unscaled_num,
					t_map_range new_range, t_map_range old_range);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);
double			atodbl(char *s);
int				key_handler(int keysym, t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				close_handler(t_fractal *fractal);
int				mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif
