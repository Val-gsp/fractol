#ifndef FRACTOL_H
# define FRACTOF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

#define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n "

#define WIDTH   800
#define HEIGHT  800


/*
 * COLORS
*/
#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

typedef struct  s_complex
{
    double x;
    double y;
}               t_complex;

typedef struct s_img
{
    void    *img_ptr;
    char    *pixels_ptr;
    int     bpp;
    int     endian;
    int     line_len;
}               t_img;

typedef struct s_fractal
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_img   img;

    double escape_value;
    int     iterations_definition;
    double  shift_x;
    double  shift_y;
    double  zoom;
    double julia_x;
    double julia_y;
     
     
}               t_fractal;

typedef struct s_map_range
{
	double min;
	double max;
} t_map_range;

// *** string utils ***
int     ft_strncmp(char *s1, char *s2, int n);
void    putstr_fd(char *s, int fd);

// *** init ***
void    fractal_init(t_fractal *fractal);

// *** render ***
void    fractal_render(t_fractal *fractal);
// static void assign_color(int x, int y, t_fractal *fractal, int i);
// static void	handle_pixel(int x, int y, t_fractal *fractal);
// static t_complex	calculate_z(int x, int y, t_fractal *fractal);
t_complex	square_complex(t_complex z);

// *** render 2 ***
void	my_pixel_put(int x, int y, t_img *img, int color);
void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal);
t_complex	calculate_z(int x, int y, t_fractal *fractal);

// *** math_utils ***
double map(double unscaled_num, t_map_range new_range, t_map_range old_range);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);
double  atodbl(char *s);

// *** hooks_event ***
int key_handler(int keysym, t_fractal *fractal);
int mouse_handler(int button, int x, int y, t_fractal *fractal);
int close_handler(t_fractal *fractal);

// *** clean up ***
int close_handler(t_fractal *fractal);
int mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif

