/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avolcy <avolcy@student.42barcelon>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:30:16 by avolcy            #+#    #+#             */
/*   Updated: 2023/12/16 19:55:47 by avolcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

 /* This function Calculates iterations for the current pixel
  * z.r = x;
  * z.i = y;
  * c.r values && c.i are constant used 
  * in the julia set equation
  */

int	julia_set(t_fract *f)
{
	t_complex	z;
//	t_complex	c;
	int iter;
	double	x_tmp;
	double	y_tmp;
	
//	c.r = -0.7;
//	c.i = 0.27015; //M_PI;
	z.r = 1.5 * (f->x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH);
	z.i = (f->y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT);//M_LOG2E;
    iter = 0;
    while (iter < f->max_iter) 
    {
        x_tmp = (z.r * z.r) - (z.i * z.i) + f->c.r;
        y_tmp = 2 * (z.r * z.i)  + f->c.i;
        z.r = x_tmp;
        z.i = y_tmp;
		if ((z.r * z.r) + (z.i * z.i) > 4)
		{
			return iter;
			//printer(f, iter * iter);
			//break ;
		}
		iter++;
    }
	return (f->max_iter - 1);
	//if (iter == f->max_iter - 1)
	//	printer(f, 0);
}
/*int color = calcul_julia_set(fract);
 * Map the color based on iterations
 * int pixel_color = (color * 255 / max_iter) << 16 | 
 * (color * 255 / max_iter) << 8 | (color * 255 / max_iter);
 *  mlx_pixel_put(fract->mlx, fract->win, x, y, pixel_color);
 */
