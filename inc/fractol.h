/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:53:24 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/11 21:05:16 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <math.h> 
#include "../libft/libft.h"

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

#define	WRONG_SET "Unrecognized set ! try one of these combs :\n./fractol julia"
#define	CORRECT_SET "./fractol mandelbrot\n./fratol burningship"
#define	JULIA_SET "Within julia try some combos from -2.0 to 2.0"

typedef struct s_fract
{
	float	x;
	float	y;
	void	*mlx;
	void	*img;
	void	*wind;
	char	*name;
	char	*im_ad;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_fract;


void    printer(t_fract *data, int color);
void    julia_set(t_fract *fract, float x, float y);
void    burning_set(t_fract *fract);
void    mandelbrot_set(t_fract *fract);
void	init_struct(t_fract *fract, char **av);

#endif
