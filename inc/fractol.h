/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:53:24 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/19 14:49:27 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h> 
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define ESC 53
# define MOVE 0.1
# define ZOOM 1.3
# define SHIFT 257
# define ZOOM_IN 5
# define WIDTH 1024
# define HEIGHT 780
# define ZOOM_OUT 4
# define LEFT_CLICK 1
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_DOWN 125
# define ARROW_RIGHT 124

# define WRONG_SET "\nIncomplete set ! try one of these combs :"
# define JULIA "\t./fractol julia"
# define CORRECT_SET "\t./fractol mandelbrot\n\t./fractol tricorn"
# define JULIA_SET "\tWithin julia try some combs from [-2.0 to 2.0]"

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_fract
{
	int			x;
	int			y;
	double		zy;
	double		zx;
	t_complex	z;
	t_complex	c;
	void		*mlx;
	void		*img;
	void		*wind;
	int			color;
	double		zoom;
	char		*name;
	char		*im_ad;
	int			endian;
	int			max_iter;
	int			line_length;
	int			bits_per_pixel;
}	t_fract;

int		cleanning(t_fract *f);
int		julia_set(t_fract *f);
int		tricorn_set(t_fract *f);
int		mandelbrot_set(t_fract *f);
int		draw_fractal(t_fract *fract);
int		key_hook(int key, t_fract *f);
int		mouse_hook(int key, int x, int y, t_fract *f);
int		check_args(int ac, char **av);
void	printer(t_fract *data, int color);
void	init_struct(t_fract *fract, char **av, int ac);
void	psychedelic_effect(int iter, t_fract *f, int pos);

#endif
